class Solution {
private:
    vector<string> ans;
public:
    void solve(unordered_map<int,string> &mp,string &d,string temp,int i)
    {
        if(i == d.size())
        {
            ans.push_back(temp);
            return;
        }
        int digit = d[i] - '0';
        for(char c : mp[digit])
        {
            temp.push_back(c);
            solve(mp,d,temp,i+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return ans;

        unordered_map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        string t = "";
        solve(mp,digits,t,0);
        return ans;
    }
};
