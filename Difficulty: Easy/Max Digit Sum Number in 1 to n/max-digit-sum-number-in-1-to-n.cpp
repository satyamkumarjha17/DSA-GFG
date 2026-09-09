class Solution {
public:
    int findMax(int n) {
        int ans = n;
        int best = 0;

        string s = to_string(n);

        for (int i = 0; i < s.size(); i++) {
            string t = s;

            if (t[i] > '0') {
                t[i]--;

                for (int j = i + 1; j < t.size(); j++)
                    t[j] = '9';

                int num = stoi(t);
                int sum = 0, x = num;

                while (x) {
                    sum += x % 10;
                    x /= 10;
                }

                if (sum > best || (sum == best && num > ans)) {
                    best = sum;
                    ans = num;
                }
            }
        }

        int sum = 0, x = n;

        while (x) {
            sum += x % 10;
            x /= 10;
        }

        if (sum > best || (sum == best && n > ans))
            ans = n;

        return ans;
    }
};