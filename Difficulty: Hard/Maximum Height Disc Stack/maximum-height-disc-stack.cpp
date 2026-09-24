class Solution {
public:
    struct Fenwick {
        int n;
        vector<int> bit;

        Fenwick(int n) : n(n), bit(n + 1, 0) {}

        void update(int i, int val) {
            while (i <= n) {
                bit[i] = max(bit[i], val);
                i += i & -i;
            }
        }

        int query(int i) {
            int ans = 0;
            while (i > 0) {
                ans = max(ans, bit[i]);
                i -= i & -i;
            }
            return ans;
        }
    };

    int maxStackHeight(vector<int>& r, vector<int>& h) {
        int n = r.size();

        vector<pair<int, int>> discs;
        for (int i = 0; i < n; i++) {
            discs.push_back({r[i], h[i]});
        }

        sort(discs.begin(), discs.end());

        vector<int> heights;
        for (auto &d : discs)
            heights.push_back(d.second);

        sort(heights.begin(), heights.end());
        heights.erase(unique(heights.begin(), heights.end()), heights.end());

        Fenwick ft(heights.size());
        int ans = 0;

        for (int i = 0; i < n;) {
            int j = i;

            while (j < n && discs[j].first == discs[i].first)
                j++;

            vector<pair<int, int>> updates;

            for (int k = i; k < j; k++) {
                int height = discs[k].second;

                int pos = lower_bound(
                    heights.begin(),
                    heights.end(),
                    height
                ) - heights.begin() + 1;

                int curr = ft.query(pos - 1) + height;

                ans = max(ans, curr);
                updates.push_back({pos, curr});
            }

            for (auto &u : updates)
                ft.update(u.first, u.second);

            i = j;
        }

        return ans;
    }
};