class Solution {
public:
    int countWays(int n, int sum) {
        if (sum > 9 * n) return -1;

        vector<vector<int>> dp(n, vector<int>(sum + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i < n; i++) {
            int window = 0;
            for (int s = 0; s <= sum; s++) {
                window += dp[i - 1][s];

                if (s >= 10)
                    window -= dp[i - 1][s - 10];

                dp[i][s] = window;
            }
        }

        int ans = 0;
        for (int first = 1; first <= 9; first++) {
            if (sum >= first) {
                if (n == 1) {
                    if (first == sum) ans++;
                } else {
                    ans += dp[n - 1][sum - first];
                }
            }
        }

        return ans == 0 ? -1 : ans;
    }
};