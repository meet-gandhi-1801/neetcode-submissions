class Solution {
private:
    vector<vector<int>> ans;
    void solve(int i,vector<int> &nums,int target,vector<int> &t)
    {
        
        if(target == 0) {ans.push_back(t);return;}
        if(i == nums.size()) return;

        solve(i+1,nums,target,t);
        if(target - nums[i] >= 0) {t.push_back(nums[i]); solve(i,nums,target - nums[i],t);
        t.pop_back();}
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> t;
       solve(0,nums,target,t); 
       return ans;
    }
};
