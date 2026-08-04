class Solution {
  public:
    int countPairs(vector<int>& arr, int k) {
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int left = 0;
        int count = 0;
        
        for (int right = 0; right < n; right++) {
            
            while (left < right && arr[right] - arr[left] >= k) {
                left++;
            }
            
            count += right - left;
        }
        
        return count;
    }
};