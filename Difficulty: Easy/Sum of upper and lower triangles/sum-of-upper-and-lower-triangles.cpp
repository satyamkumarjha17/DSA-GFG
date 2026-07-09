class Solution {
  public:
    vector<int> sumTriangles(vector<vector<int>>& mat) {
        // code here
        //SumOfUpperTriangle = SOUT
        //SumOflowerTriangle = SOLT
        vector<int> ans;
        int SOUT = 0;
        for(int i=0; i<mat.size();i++){
            for(int j = i; j<mat[0].size();j++){
                SOUT+=mat[i][j];
            }
        }
                
        int SOLT = 0;
        for(int i=0; i<mat.size();i++){
            for(int j = 0; j<=i;j++){
                SOLT+=mat[i][j];
            }
        }
        ans.push_back(SOUT);
        ans.push_back(SOLT);
        
        return ans;
    }
};
