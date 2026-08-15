class Solution {
  public:
    int countWithout(int n, int d) {
        if (n == 0)
            return 0;

        string s = to_string(n);
        long long dp[2][2] = {};
        dp[1][0] = 1;

        for (char c : s) {
            int limit = c - '0';
            long long ndp[2][2] = {};

            for (int tight = 0; tight <= 1; tight++) {
                for (int started = 0; started <= 1; started++) {
                    for (int x = 0; x <= (tight ? limit : 9); x++) {
                        if (x == d && (started || x != 0))
                            continue;

                        int ntight = tight && (x == limit);
                        int nstarted = started || x != 0;

                        ndp[ntight][nstarted] += dp[tight][started];
                    }
                }
            }

            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    dp[i][j] = ndp[i][j];
        }

        return dp[0][1] + dp[1][1];
    }
};