class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;

        vector<int> jump(N + 1, 0);
        vector<int> dist(N + 1, -1);

        for (int i = 0; i < lad.size(); i += 2)
            jump[lad[i]] = lad[i + 1];

        for (int i = 0; i < sn.size(); i += 2)
            jump[sn[i]] = sn[i + 1];

        queue<int> q;
        q.push(1);
        dist[1] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == N)
                return dist[curr];

            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;

                if (next > N)
                    break;

                if (jump[next] != 0)
                    next = jump[next];

                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};