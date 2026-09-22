class Solution {
public:
    string findLongestWord(string &s, vector<string> &d) {
        int n = s.size();

        vector<array<int, 26>> nxt(n + 1);

        for (int c = 0; c < 26; c++)
            nxt[n][c] = -1;

        for (int i = n - 1; i >= 0; i--) {
            nxt[i] = nxt[i + 1];
            nxt[i][s[i] - 'a'] = i;
        }

        auto isSubsequence = [&](const string& word) {
            int pos = 0;

            for (char c : word) {
                if (pos > n - 1)
                    return false;

                int idx = nxt[pos][c - 'a'];

                if (idx == -1)
                    return false;

                pos = idx + 1;
            }

            return true;
        };

        string ans = "";

        for (const string& word : d) {
            if (!isSubsequence(word))
                continue;

            if (word.size() > ans.size() ||
                (word.size() == ans.size() && word < ans)) {
                ans = word;
            }
        }

        return ans;
    }
};