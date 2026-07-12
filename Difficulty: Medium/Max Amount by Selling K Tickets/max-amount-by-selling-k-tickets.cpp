class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {
        const long long MOD = 1e9 + 7;

        sort(arr.begin(), arr.end(), greater<int>());
        arr.push_back(0);

        long long ans = 0;
        int n = arr.size();

        for (int i = 0; i < n - 1 && k > 0; i++) {
            long long curr = arr[i];
            long long next = arr[i + 1];
            long long sellers = i + 1;

            long long diff = curr - next;
            long long totalTickets = sellers * diff;

            if (k >= totalTickets) {
                long long sum = (curr + next + 1) * diff / 2;
                ans = (ans + sellers * sum) % MOD;
                k -= totalTickets;
            } else {
                long long fullLevels = k / sellers;
                long long rem = k % sellers;

                long long low = curr - fullLevels;

                long long sum = (curr + low + 1) * fullLevels / 2;
                ans = (ans + sellers * sum) % MOD;
                ans = (ans + rem * low) % MOD;

                k = 0;
            }
        }

        return ans % MOD;
    }
};