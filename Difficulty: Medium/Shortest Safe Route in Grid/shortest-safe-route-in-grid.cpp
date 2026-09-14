class Solution {
public:
    int shortestPath(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> unsafe(n, vector<int>(m, 0));
        vector<vector<int>> dist(n, vector<int>(m, -1));

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    unsafe[i][j] = 1;

                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];

                        if (x >= 0 && x < n && y >= 0 && y < m) {
                            unsafe[x][y] = 1;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (!unsafe[i][0]) {
                q.push({i, 0});
                dist[i][0] = 1;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (y == m - 1) {
                return dist[x][y];
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    !unsafe[nx][ny] && dist[nx][ny] == -1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }

        return -1;
    }
};