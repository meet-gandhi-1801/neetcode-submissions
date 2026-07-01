class Solution {
private:
    vector<vector<int>> ans;
    
    void solve(int i,vector<int> &nums,int target,vector<int> &t)
    {
        
        if(target == 0) 
        
            {ans.push_back(t);return;}
            
        
        if(i == nums.size()) return;
        

        int j = i + 1;
while (j < nums.size() && nums[j] == nums[i])
    j++;

solve(j, nums, target, t);
        if(target - nums[i] >= 0) {t.push_back(nums[i]); solve(i+1,nums,target - nums[i],t);
        t.pop_back();}
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        
        vector<int> t;
       solve(0,nums,target,t); 
       return ans;
    }
};
