class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,pair<int,int>>> pq;
        int x,y;
        double dist;
        for(auto &v : points)
        {
            x = abs(v[0]);
            y = abs(v[1]);
            dist = 1LL * sqrt(((1LL * x) * (1LL*  x)) + ((1LL * y) * (1LL * y)));
            pq.push({dist,{v[0],v[1]}});
        }
        while(pq.size() > k)
        {
            pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
            vector<int> t;
            auto p = pq.top();
            pq.pop();
            t.push_back(p.second.first);
            t.push_back(p.second.second);
            ans.push_back(t);
        }
        return ans;      
    }
};