class Solution {
public:
    long long maxProduct(vector<int>& arr, int k) {
        int n = arr.size();

        const long long INF = 4e18;

        vector<vector<long long>> mx(k + 1, vector<long long>(n + 1, -INF));
        vector<vector<long long>> mn(k + 1, vector<long long>(n + 1, INF));

        for (int i = 0; i <= n; i++) {
            mx[0][i] = 1;
            mn[0][i] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                mx[j][i] = mx[j][i - 1];
                mn[j][i] = mn[j][i - 1];

                if (mx[j - 1][i - 1] != -INF) {
                    long long x = mx[j - 1][i - 1] * arr[i - 1];
                    mx[j][i] = max(mx[j][i], x);
                    mn[j][i] = min(mn[j][i], x);
                }

                if (mn[j - 1][i - 1] != INF) {
                    long long x = mn[j - 1][i - 1] * arr[i - 1];
                    mx[j][i] = max(mx[j][i], x);
                    mn[j][i] = min(mn[j][i], x);
                }
            }
        }

        return mx[k][n];
    }
};