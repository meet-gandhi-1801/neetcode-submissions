class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        const int INF = 1e9;
        vector<int> dist(n, INF);
        dist[src] = 0;

        // Relax all edges k+1 times
        for (int i = 0; i <= k; i++) {
            vector<int> temp = dist;

            for (auto &flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int wt = flight[2];

                if (dist[u] == INF)
                    continue;

                temp[v] = min(temp[v], dist[u] + wt);
            }

            dist = temp;
        }

        return dist[dst] == INF ? -1 : dist[dst];
    }
};