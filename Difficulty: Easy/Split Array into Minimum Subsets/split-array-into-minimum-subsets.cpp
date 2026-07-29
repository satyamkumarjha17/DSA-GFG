class Solution {
public:
    int minSubsets(vector<int>& arr) {
        unordered_set<int> st(arr.begin(), arr.end());

        int count = 0;

        for (int x : arr) {
            if (st.find(x - 1) == st.end()) {
                count++;
            }
        }

        return count;
    }
};