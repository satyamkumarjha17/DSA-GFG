class Solution {
public:
    int formPyramid(vector<int>& arr) {
        int n = arr.size();

        vector<long long> left(n), right(n);

        left[0] = min(1LL, (long long)arr[0]);

        for (int i = 1; i < n; i++) {
            left[i] = min((long long)arr[i], left[i - 1] + 1);
        }

        right[n - 1] = min(1LL, (long long)arr[n - 1]);

        for (int i = n - 2; i >= 0; i--) {
            right[i] = min((long long)arr[i], right[i + 1] + 1);
        }

        long long maxHeight = 0;
        long long totalSum = 0;

        for (int x : arr) {
            totalSum += x;
        }

        for (int i = 0; i < n; i++) {
            long long height = min({
                left[i],
                right[i],
                (long long)i + 1,
                (long long)n - i
            });

            maxHeight = max(maxHeight, height);
        }

        return totalSum - maxHeight * maxHeight;
    }
};