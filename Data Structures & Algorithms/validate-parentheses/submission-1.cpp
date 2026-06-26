class Solution {
public:
    char solve(char c)
    {
        if(c == ')') return '(';
        else if(c == '}') return '{';
        else return '[';
    }
    bool isValid(string st) {

        stack<char> s;
        for(char c : st)
        {
            if(c == '(' || c == '{' || c == '[') s.push(c);
            else
            {
                char t = solve(c);
                if(s.empty() || s.top() != t) return false;
                else s.pop();
            }
        }

        if(s.size() != 0 ) return false;
        return true;
        
    }
};
