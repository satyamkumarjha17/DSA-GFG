class Solution {
public:
    pair<int, int> bfs(int start, vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> dist(n, -1);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        int farthest = start;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int x : adj[u]) {
                int v = x - 1; 

                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);

                    if (dist[v] > dist[farthest]) {
                        farthest = v;
                    }
                }
            }
        }

        return {farthest, dist[farthest]};
    }

    int partyHouse(vector<vector<int>>& adj) {
        // Find one end of the diameter
        int A = bfs(0, adj).first;

        // Find the diameter length
        int diameter = bfs(A, adj).second;

        // Minimum maximum distance
        return (diameter + 1) / 2;
    }
};