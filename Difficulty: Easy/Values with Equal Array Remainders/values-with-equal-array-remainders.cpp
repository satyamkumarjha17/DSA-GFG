class Solution {
public:
    int sameMod(vector<int> &arr) {
        int mn = *min_element(arr.begin(), arr.end());
        int g = 0;

        for (int x : arr) {
            g = gcd(g, x - mn);
        }

        if (g == 0)
            return -1;

        int ans = 0;

        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                ans++;

                if (i != g / i)
                    ans++;
            }
        }

        return ans;
    }
};