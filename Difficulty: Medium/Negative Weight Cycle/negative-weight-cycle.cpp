class Solution {
  public:
    bool isNegativeWeightCycle(int V, vector<vector<int>>& edges) {

        vector<long long> dist(V, 0);

        for (int i = 0; i < V - 1; i++) {
            for (int j = 0; j < edges.size(); j++) {

                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if (dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for (int j = 0; j < edges.size(); j++) {

            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] + wt < dist[v]) {
                return true;
            }
        }

        return false;
    }
};