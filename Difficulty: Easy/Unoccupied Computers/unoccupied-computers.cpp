class Solution {
  public:
    int solve(int n, string s) {
        int state[26] = {0};
        int occupied = 0;
        int rejected = 0;

        for (char c : s) {
            int id = c - 'A';

            if (state[id] == 0) {
                if (occupied < n) {
                    occupied++;
                    state[id] = 1;
                } else {
                    rejected++;
                    state[id] = 2;
                }
            } else if (state[id] == 1) {
                occupied--;
            }
        }

        return rejected;
    }
};
