class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int maxi = 0;
        int i = 0;
        for(int j = 0;j<s.size();j++)
        {
            char c = s[j];
            mp[c]++;
            
                while(mp[c] > 1)
                {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
            
            if(mp.size() > maxi) maxi = mp.size();
        }
            if(mp.size() > maxi) maxi = mp.size();
        return maxi;

    }
};
