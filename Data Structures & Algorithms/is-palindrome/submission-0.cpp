class Solution {
public:
    bool iss(char c)
    {
        return isalnum(c);
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j)
        {
            while(i < j && !iss(s[i])) i++;
            while(i < j && !iss(s[j])) j--;

            if(tolower(s[i]) != tolower(s[j]))
                return false;

            i++;
            j--;
        }

        return true;
    }
};