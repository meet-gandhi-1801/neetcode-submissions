class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mp;

        for(int n : nums)
        {
            if(mp.find(n) != mp.end()) return true;
            else mp[n] = true;
        }

        return false;
    }
};