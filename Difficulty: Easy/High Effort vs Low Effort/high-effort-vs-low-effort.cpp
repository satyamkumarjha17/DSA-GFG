class Solution {
public:
    int maxTask(vector<int>& h, vector<int>& l) {

        int n = h.size();

        int prev2 = 0;
        int prev1 = max(h[0], l[0]);

        for (int i = 1; i < n; i++) {

            int low = prev1 + l[i];

            int high = prev2 + h[i];

            int current = max(low, high);

            prev2 = prev1;
            prev1 = current;
        }

        return prev1;
    }
};