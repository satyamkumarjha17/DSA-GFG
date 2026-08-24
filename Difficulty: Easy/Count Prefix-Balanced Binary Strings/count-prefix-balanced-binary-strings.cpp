class Solution {
  public:
    int prefixStrings(int n) {
        const int MOD = 1000000007;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int ones = 0; ones <= n; ones++) {
            for (int zeros = 1; zeros <= n; zeros++) {
                if (zeros > ones)
                    dp[zeros] = 0;
                else
                    dp[zeros] = (dp[zeros] + dp[zeros - 1]) % MOD;
            }
        }

        return dp[n];
    }
};