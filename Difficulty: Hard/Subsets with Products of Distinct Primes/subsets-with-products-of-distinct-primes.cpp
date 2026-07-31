class Solution {
public:
    static const int MOD = 1e9 + 7;

    int countSubsets(vector<int> &arr) {

        vector<int> freq(31, 0);
        for (int x : arr)
            freq[x]++;

        vector<int> primes = {2,3,5,7,11,13,17,19,23,29};


        vector<int> mask(31, -1);

        mask[1] = 0;

        for (int x = 2; x <= 30; x++) {

            int t = x;
            int m = 0;
            bool ok = true;

            for (int i = 0; i < 10; i++) {
                int p = primes[i];

                int cnt = 0;
                while (t % p == 0) {
                    cnt++;
                    t /= p;
                }

                if (cnt > 1) {
                    ok = false;
                    break;
                }

                if (cnt == 1)
                    m |= (1 << i);
            }

            if (ok)
                mask[x] = m;
        }

        vector<long long> dp(1 << 10, 0);
        dp[0] = 1;

        for (int val = 2; val <= 30; val++) {

            if (freq[val] == 0 || mask[val] == -1)
                continue;

            int curMask = mask[val];

            for (int s = (1 << 10) - 1; s >= 0; s--) {

                if ((s & curMask) == 0) {
                    dp[s | curMask] =
                        (dp[s | curMask] + dp[s] * freq[val]) % MOD;
                }
            }
        }

        long long ways1 = 1;
        for (int i = 0; i < freq[1]; i++)
            ways1 = (ways1 * 2) % MOD;

        long long ans = 0;

        for (int s = 1; s < (1 << 10); s++)
            ans = (ans + dp[s]) % MOD;

        ans = (ans * ways1) % MOD;

        return (int)ans;
    }
};