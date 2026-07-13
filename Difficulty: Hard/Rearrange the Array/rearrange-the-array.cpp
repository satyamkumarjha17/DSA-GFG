class Solution {
public:
    static const int MOD = 1000000007;

    int minOperations(vector<int> &b) {
        int n = b.size();

        vector<bool> vis(n, false);
        vector<int> cycleLengths;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int cur = i;
                int len = 0;

                while (!vis[cur]) {
                    vis[cur] = true;
                    cur = b[cur] - 1;  
                    len++;
                }

                cycleLengths.push_back(len);
            }
        }

        vector<int> primes;
        vector<bool> isPrime(n + 1, true);

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                primes.push_back(i);
                for (int j = i * 2; j <= n; j += i)
                    isPrime[j] = false;
            }
        }

        unordered_map<int, int> maxExp;

        for (int len : cycleLengths) {
            int x = len;

            for (int p : primes) {
                if (p * p > x)
                    break;

                if (x % p == 0) {
                    int cnt = 0;
                    while (x % p == 0) {
                        x /= p;
                        cnt++;
                    }
                    maxExp[p] = max(maxExp[p], cnt);
                }
            }

            if (x > 1)
                maxExp[x] = max(maxExp[x], 1);
        }

        long long ans = 1;

        for (auto &it : maxExp) {
            int p = it.first;
            int e = it.second;

            long long cur = 1;
            while (e--) {
                cur = (cur * p) % MOD;
            }

            ans = (ans * cur) % MOD;
        }

        return (int)ans;
    }
};