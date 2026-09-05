class Solution {
  public:
    int longestSubseq(vector<int>& arr) {
        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : arr) {
            dp[x] = max(dp[x], max(dp[x - 1], dp[x + 1]) + 1);
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};