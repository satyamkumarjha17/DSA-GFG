class Solution {
public:
    int minProd(vector<int>& arr) {
        int n = arr.size();

        int negativeCount = 0;
        int zeroCount = 0;
        int smallestNegative = INT_MAX;
        int smallestPositive = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (arr[i] < 0) {
                negativeCount++;

                if (abs(arr[i]) < smallestNegative) {
                    smallestNegative = abs(arr[i]);
                }
            }
            else if (arr[i] == 0) {
                zeroCount++;
            }
            else {
                if (arr[i] < smallestPositive) {
                    smallestPositive = arr[i];
                }
            }
        }

        long long product = 1;

        // Odd number of negative elements
        if (negativeCount % 2 == 1) {
            for (int i = 0; i < n; i++) {
                if (arr[i] != 0) {
                    product *= arr[i];
                }
            }

            return product;
        }

        // Even number of negative elements
        if (negativeCount > 0) {
            bool removed = false;

            for (int i = 0; i < n; i++) {
                if (arr[i] < 0 && abs(arr[i]) == smallestNegative && !removed) {
                    removed = true;
                    continue;
                }

                if (arr[i] != 0) {
                    product *= arr[i];
                }
            }

            return product;
        }

        // No negative elements
        if (zeroCount > 0) {
            return 0;
        }

        return smallestPositive;
    }
};