class Solution {
public:
    int n;
    vector<int> arr;
    vector<vector<int>> dp;

    int solve(int inc, int dec) {
        // Elements must come after both last selected indices
        int start = max(inc, dec) + 1;

        if (start >= n)
            return 0;

        if (dp[inc + 1][dec + 1] != -1)
            return dp[inc + 1][dec + 1];

        int ans = 0;

        for (int k = start; k < n; k++) {

            // Put arr[k] in increasing subsequence
            if (inc == -1 || arr[k] > arr[inc]) {
                ans = max(ans, 1 + solve(k, dec));
            }

            // Put arr[k] in decreasing subsequence
            if (dec == -1 || arr[k] < arr[dec]) {
                ans = max(ans, 1 + solve(inc, k));
            }
        }

        return dp[inc + 1][dec + 1] = ans;
    }

    int minCount(vector<int>& a) {
        arr = a;
        n = arr.size();

        // +1 because index -1 is also stored
        dp.assign(n + 1, vector<int>(n + 1, -1));

        int maximumUsed = solve(-1, -1);

        return n - maximumUsed;
    }
};