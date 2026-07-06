class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<vector<int>> ans;
        sort(in.begin(),in.end());

        for(auto &v : in)
        {
            if(ans.size() == 0)
            {
                ans.push_back(v);
            }
            auto &p = ans.back();
            if(p[1] < v[0])
            {
                ans.push_back(v);
            }
            else{
                p[0] = min(p[0],v[0]);
                p[1] = max(p[1],v[1]);
            }
        }
        return ans;

    }
};
