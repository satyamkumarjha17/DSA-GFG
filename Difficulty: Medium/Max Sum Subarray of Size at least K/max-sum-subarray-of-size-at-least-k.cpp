class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();

        int windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += arr[i];
        }

        int ans = windowSum;
        int extraSum = 0;

        for (int i = k; i < n; i++) {
            windowSum += arr[i];
            windowSum -= arr[i - k];

            extraSum = max(arr[i - k], extraSum + arr[i - k]);

            ans = max(ans, windowSum);

            if (extraSum > 0) {
                ans = max(ans, windowSum + extraSum);
            }
        }

        return ans;
    }
};