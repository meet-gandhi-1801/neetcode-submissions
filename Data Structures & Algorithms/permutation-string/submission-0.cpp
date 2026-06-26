class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size() < s1.size()) return false;
        unordered_map<char,int> mp1;

        for(char c : s1)
        {
            mp1[c]++;
        }
    int i = 0;
        unordered_map<char,int> mp2;

        int j = 0;
        while(j<s1.size() && j <s2.size())
        {
            mp2[s2[j++]]++;
        }
        if(mp2 == mp1) return true;
        while(j < s2.size())
        {
            mp2[s2[i]]--;
            if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
            i++;
            mp2[s2[j++]]++;

            if(mp2 == mp1) return true;
        }
        return false;
    }
};
