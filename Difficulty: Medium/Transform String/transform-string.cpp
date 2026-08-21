class Solution {
  public:
    int transform(string &s1, string &s2) {
        if (s1.length() != s2.length()) {
            return -1;
        }

        int freq[256] = {0};

        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i]]++;
        }

        for (int i = 0; i < s2.length(); i++) {
            freq[s2[i]]--;
        }

        for (int i = 0; i < 256; i++) {
            if (freq[i] != 0) {
                return -1;
            }
        }

        int i = s1.length() - 1;
        int j = s2.length() - 1;
        int operations = 0;

        while (i >= 0) {
            if (s1[i] == s2[j]) {
                i--;
                j--;
            } else {
                i--;
                operations++;
            }
        }

        return operations;
    }
};