class Solution {
public:
    bool isPossible(vector<int>& arr, int s, int x) {
        vector<long long> seq;

        long long total = s;
        seq.push_back(s);

        for (int a : arr) {
            long long next = total + a;

            // All future numbers will be even larger,
            // so we don't need to generate them.
            if (next > x)
                break;

            seq.push_back(next);
            total += next;
        }

        // Greedy subset sum because the sequence is superincreasing
        for (int i = seq.size() - 1; i >= 0; i--) {
            if (seq[i] <= x) {
                x -= seq[i];
            }
        }

        return x == 0;
    }
};