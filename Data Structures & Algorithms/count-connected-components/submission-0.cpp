class Solution {
private:
    void bfs(int u,vector<vector<int>> &adj,vector<bool> &vis)
    {
        vis[u]= true;
        for(int v : adj[u])
        {
            if(!vis[v])
            {
                bfs(v,adj,vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &e: edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n,false);
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
            if(!vis[i])
            {
                bfs(i,adj,vis);
                ans++;
            }
        }
        return ans;
    }
};
