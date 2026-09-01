class Solution {
  public:
    int palindromicStrings(int n, int k) {
        const long long MOD = 1000000007;

        long long ans = k;
        long long perm = 1;

        for (int m = 1; 2 * m <= n; m++) {
            perm = perm * (k - m + 1) % MOD;

            ans = (ans + perm) % MOD;

            if (2 * m + 1 <= n) {
                long long odd = perm * (k - m) % MOD;
                ans = (ans + odd) % MOD;
            }
        }

        return ans;
    }
};