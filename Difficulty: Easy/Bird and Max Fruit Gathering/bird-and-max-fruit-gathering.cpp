class Solution {
  public:
    int maxFruits(vector<int>& arr, int m) {
        int n = arr.size();

        if (m >= n) {
            long long sum = 0;
            for (int x : arr)
                sum += x;
            return (int)sum;
        }

        long long sum = 0;

        for (int i = 0; i < m; i++)
            sum += arr[i];

        long long ans = sum;

        for (int i = 1; i < n; i++) {
            sum -= arr[i - 1];
            sum += arr[(i + m - 1) % n];
            ans = max(ans, sum);
        }

        return (int)ans;
    }
};