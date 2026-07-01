class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});

        for (int n : nums) {
            int sz = ans.size();

            for (int i = 0; i < sz; i++) {
                vector<int> t = ans[i];
                t.push_back(n);
                ans.push_back(t);
            }
        }

        return ans;
    }
};