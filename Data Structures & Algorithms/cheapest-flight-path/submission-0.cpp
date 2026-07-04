class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& f : flights) adj[f[0]].push_back({f[1], f[2]});

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));

        dist[src][0] = 0;
        pq.push({0, {src, 0}});

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            int d = p.first;
            int u = p.second.first;
            int edges = p.second.second;

            if (d > dist[u][edges]) continue;

            if (u == dst) return d;

            if (edges == k + 1) continue;

            for (auto& [v, wt] : adj[u]) {
                if (dist[v][edges + 1] > d + wt) {
                    dist[v][edges + 1] = d + wt;

                    pq.push({d + wt, {v, edges + 1}});
                }
            }
        }

        return -1;
    }
};