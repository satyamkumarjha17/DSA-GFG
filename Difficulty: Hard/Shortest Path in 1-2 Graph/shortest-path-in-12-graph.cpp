class Solution {
public:
    int shortestPath(int V, int src, int dest, vector<vector<int>> &edges) {

        int newV = V;

        // Maximum vertices = V + number of weight-2 edges
        vector<vector<int>> adj(V + edges.size() + 5);

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (w == 1) {
                adj[u].push_back(v);
                adj[v].push_back(u);
            } else {
                int dummy = newV++;

                adj[u].push_back(dummy);
                adj[dummy].push_back(u);

                adj[dummy].push_back(v);
                adj[v].push_back(dummy);
            }
        }

        vector<int> dist(newV, -1);
        queue<int> q;

        q.push(src);
        dist[src] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            if (node == dest)
                return dist[node];

            for (int nxt : adj[node]) {
                if (dist[nxt] == -1) {
                    dist[nxt] = dist[node] + 1;
                    q.push(nxt);
                }
            }
        }

        return -1;
    }
};