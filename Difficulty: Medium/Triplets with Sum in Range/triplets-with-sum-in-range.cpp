class Solution {
  public:
      long long countTriplets(vector<int> &arr, int l, int r) {
          sort(arr.begin(), arr.end());

          auto count = [&](int target) {
              long long ans = 0;
              int n = arr.size();

              for (int i = 0; i < n - 2; i++) {
                  int left = i + 1;
                  int right = n - 1;

                  while (left < right) {
                      long long sum = (long long)arr[i] + arr[left] + arr[right];

                      if (sum <= target) {
                          ans += right - left;
                          left++;
                      } else {
                          right--;
                      }
                  }
              }

              return ans;
          };

          return count(r) - count(l - 1);
      }
  };