class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        // vector<int>res;
        // int n = arr.size();
        // for(int i = 0; i< n; i++){
        //     int j;
        //     for( j = i+1; j < n; j++){
        //         if(arr[i] < arr[j])
        //             break;
        //     }
        //     if (j == n) 
        //         res.push_back(arr[i]);
        // }
        // return res;
        vector<int>res;
        int n = arr.size();
        int maxRight = arr[n-1];
        res.push_back(maxRight);
        
        for(int i = n-2; i >= 0; i--){
            if(arr[i] >= maxRight){
               maxRight = arr[i];
               res.push_back(arr[i]);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};