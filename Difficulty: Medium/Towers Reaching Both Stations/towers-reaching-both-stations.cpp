class Solution {
public:
    int countCoordinates(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<bool>> p(n, vector<bool>(m, false));
        vector<vector<bool>> q(n, vector<bool>(m, false));

        queue<pair<int, int>> qp, qq;

        for (int j = 0; j < m; j++) {
            if (!p[0][j]) {
                p[0][j] = true;
                qp.push({0, j});
            }
        }

        for (int i = 0; i < n; i++) {
            if (!p[i][0]) {
                p[i][0] = true;
                qp.push({i, 0});
            }
        }

        for (int j = 0; j < m; j++) {
            if (!q[n - 1][j]) {
                q[n - 1][j] = true;
                qq.push({n - 1, j});
            }
        }

        for (int i = 0; i < n; i++) {
            if (!q[i][m - 1]) {
                q[i][m - 1] = true;
                qq.push({i, m - 1});
            }
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        auto bfs = [&](queue<pair<int, int>> &qu, vector<vector<bool>> &vis) {
            while (!qu.empty()) {
                auto [x, y] = qu.front();
                qu.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        !vis[nx][ny] &&
                        mat[nx][ny] >= mat[x][y]) {
                        vis[nx][ny] = true;
                        qu.push({nx, ny});
                    }
                }
            }
        };

        bfs(qp, p);
        bfs(qq, q);

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (p[i][j] && q[i][j])
                    ans++;
            }
        }

        return ans;
    }
};