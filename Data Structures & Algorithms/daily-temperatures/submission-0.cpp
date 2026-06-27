class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        int n = t.size();
        vector<int> result(n);
        for(int i = n-1;i>=0;i--)
        {
            while(!s.empty() && t[s.top()] <= t[i]) s.pop();
            if(!s.empty()) result[i] = s.top() - i;
            else result[i] = 0;

            s.push(i);
        }
        return result;
        
    }
};
