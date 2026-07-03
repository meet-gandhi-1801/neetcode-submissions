class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if(edges.size() != n-1)
            return false;

        vector<vector<int>> adj(n);

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n,false);

        queue<int> q;
        q.push(0);
        vis[0]=true;

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int v:adj[u]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }

        for(bool x:vis)
            if(!x) return false;

        return true;
    }
};