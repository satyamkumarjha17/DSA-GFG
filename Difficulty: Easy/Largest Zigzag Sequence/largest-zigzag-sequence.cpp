class Solution {
public:
    int zigzagSequence(vector<vector<int>>& mat) {
        
        int n = mat.size();

        vector<int> dp(n);

        for (int j = 0; j < n; j++) {
            dp[j] = mat[0][j];
        }

        for (int i = 1; i < n; i++) {

            int maxi = -1;
            int secondMaxi = -1;
            int maxCol = -1;

            for (int j = 0; j < n; j++) {
                if (dp[j] > maxi) {
                    secondMaxi = maxi;
                    maxi = dp[j];
                    maxCol = j;
                }
                else if (dp[j] > secondMaxi) {
                    secondMaxi = dp[j];
                }
            }

            vector<int> newdp(n);

            for (int j = 0; j < n; j++) {

                if (j == maxCol) {
                    newdp[j] = mat[i][j] + secondMaxi;
                }
                else {
                    newdp[j] = mat[i][j] + maxi;
                }
            }

            dp = newdp;
        }

        return *max_element(dp.begin(), dp.end());
    }
};