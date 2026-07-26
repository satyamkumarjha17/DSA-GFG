class Solution {
public:
    vector<vector<int>> levelSort(vector<int>& arr) {

        vector<vector<int>> ans;

        int n = arr.size();
        int idx = 0;
        int levelSize = 1;

        while (idx < n) {

            vector<int> level;

            int cnt = min(levelSize, n - idx);

            for (int i = 0; i < cnt; i++) {
                level.push_back(arr[idx++]);
            }

            sort(level.begin(), level.end());

            ans.push_back(level);

            levelSize *= 2;
        }

        return ans;
    }
};