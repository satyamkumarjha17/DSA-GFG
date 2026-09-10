class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int MIN = arr[0];
        int MAX = arr[0];
        
        for(int i = 0; i < arr.size(); i++){
            if(MIN > arr[i]){
                MIN = arr[i];
            }
            if(MAX < arr[i]){
                MAX = arr[i];
            }
        }
        return{MIN, MAX};
    }
};