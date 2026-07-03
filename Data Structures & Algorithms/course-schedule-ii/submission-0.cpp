class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& e) {
        vector<vector<int>> adj(n);
        vector<int> in(n);
        for (auto& v : e) {
            adj[v[1]].push_back(v[0]);
            in[v[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (in[i] == 0) q.push(i);
        }
        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for(auto &v : adj[u])
            {
                in[v]--;
                if(in[v] == 0) q.push(v);
            }
        }
        vector<int> t;
        return topo.size() == n ? topo : t;
    }
};
