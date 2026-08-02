class Solution {
public:
    int count(int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 1; j <= m; j++) {
            dp[1][j] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= m; k++) {
                    if (j % k == 0 || k % j == 0) {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }

        int ans = 0;

        for (int j = 1; j <= m; j++) {
            ans += dp[n][j];
        }

        return ans;
    }
};