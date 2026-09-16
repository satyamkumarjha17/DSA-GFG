class Solution {
public:
    int dominantPairs(vector<int> &arr) {
        int n = arr.size();
        int mid = n / 2;
        long long ans = 0;

        vector<int> second(arr.begin() + mid, arr.end());
        sort(second.begin(), second.end());

        for (int i = 0; i < mid; i++) {
            long long x = arr[i];

            int l = 0, r = mid;
            while (l < r) {
                int m = l + (r - l) / 2;

                if (5LL * second[m] <= x)
                    l = m + 1;
                else
                    r = m;
            }

            ans += l;
        }

        return ans;
    }
};