class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        if(nums.size() == 0) return 0;
        for(int n : nums)
        {
            s.insert(n);
        }
        int maxi = 1;
        for(auto n : s)
        {int curr = 0;
            if(s.find(n-1) == s.end())
            {
                while(s.find(n++) != s.end()) curr++;
            }
            maxi = max(curr,maxi);
        }
        return maxi;
    }
};
