class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        
        int incrementOps = 0;
        int maxElement = 0;

        for (int num : arr) {
            maxElement = max(maxElement, num);

            while (num > 0) {
                if (num % 2 == 1) {
                    incrementOps++;
                }

                num /= 2;
            }
        }

        int doubleOps = 0;

        while (maxElement > 1) {
            maxElement /= 2;
            doubleOps++;
        }

        return incrementOps + doubleOps;
    }
};