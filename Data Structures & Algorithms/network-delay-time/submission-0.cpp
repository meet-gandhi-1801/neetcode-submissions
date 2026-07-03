class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto &t : times)
        {
            adj[t[0] - 1].push_back({t[1] - 1,t[2]});
        }
        k--;
        vector<int> time(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>    pq;
        time[k] = 0;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto p = pq.top();
            int t = p.first;
            int u = p.second;
            pq.pop();
            if(t > time[u]) continue;
            for(auto &v : adj[u])
            {
                if(time[v.first] > t + v.second)
                {
                    time[v.first] = t + v.second;
                    pq.push({time[v.first],v.first});
                }
            }
        }
        int ans = INT_MIN;
        for(int a : time)
        {
         ans = max(ans,a);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
