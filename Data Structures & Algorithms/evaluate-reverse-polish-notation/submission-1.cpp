class Solution {
    public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for(string a : tokens)
        {
            if((a == "+"))
            {
                
                int x=0,y=0;
                if(!s.empty()) {x = s.top();s.pop();}
                if(!s.empty()) {y = s.top();s.pop();}
                s.push(y+x);
            }
            else if((a == "-"))
            {
                
                int x=0,y=0;
                if(!s.empty()) {x = s.top();s.pop();}
                if(!s.empty()) {y = s.top();s.pop();}
                s.push(y-x);
            }
            else if((a == "*"))
            {
                
                int x=0,y=0;
                if(!s.empty()) {x = s.top();s.pop();}
                if(!s.empty()) {y = s.top();s.pop();}
                s.push(y*x);
            }
            else if((a == "/"))
            {
                
                int x=0,y=1;
                if(!s.empty()) {x = s.top();s.pop();}
                if(!s.empty()) {y = s.top();s.pop();}
                s.push(y/x);
            }
            else s.push(stoi(a));
        }
        return s.top();
        
    }
};
