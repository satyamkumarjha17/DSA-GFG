class Solution {
  public:
    int largestArea(int n, int m, vector<vector<int>> &arr) {
        vector<int> rows = {0, n + 1};
        vector<int> cols = {0, m + 1};

        for (auto &x : arr) {
            rows.push_back(x[0]);
            cols.push_back(x[1]);
        }

        sort(rows.begin(), rows.end());
        sort(cols.begin(), cols.end());

        int maxRows = 0, maxCols = 0;

        for (int i = 1; i < rows.size(); i++)
            maxRows = max(maxRows, rows[i] - rows[i - 1] - 1);

        for (int i = 1; i < cols.size(); i++)
            maxCols = max(maxCols, cols[i] - cols[i - 1] - 1);

        return maxRows * maxCols;
    }
};