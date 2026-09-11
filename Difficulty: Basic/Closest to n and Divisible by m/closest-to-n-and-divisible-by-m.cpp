// class Solution {
// public:
//     int closestNumber(int n, int m) {
//         int x = n;

//         while (true) {
//             if (x % m == 0)
//                 return x;

//             x--;
//         }
//     }
// };
class Solution {
public:
    int closestNumber(int n, int m) {
        int q = n / m;

        int lower = q * m;
        int upper;

        if (n * m > 0)
            upper = (q + 1) * m;
        else
            upper = (q - 1) * m;

        int d1 = abs(n - lower);
        int d2 = abs(n - upper);

        if (d1 < d2)
            return lower;
        else if (d2 < d1)
            return upper;
        else
            return (abs(lower) > abs(upper)) ? lower : upper;
    }
};