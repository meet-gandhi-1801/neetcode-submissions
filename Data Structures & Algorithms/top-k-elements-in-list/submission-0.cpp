class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { 
        unordered_map<int,int> mp;

        for(int n : nums) {
            
            mp[n]++;        
        }
        vector<pair<int,int>> ans;
        for(auto &p : mp)
        {
            ans.push_back(make_pair(p.second,p.first));
        }

        sort(ans.rbegin(),ans.rend());
        vector<int> result;
        for(int i = 0;i<k && i < ans.size();i++)
        {
            result.push_back(ans[i].second);
        }

        return result;
    }
};
