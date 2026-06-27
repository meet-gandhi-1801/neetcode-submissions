class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        stack<pair<int,int>> s;
        int maxi = 0;

        for(int i = 0;i<heights.size();i++)
        {int indi = -1;
            while(!s.empty() && s.top().first > heights[i])
            {
                auto p = s.top();
                s.pop();
                maxi = max(maxi,(p.first*(i - p.second)));
                indi = p.second;
            }
            if(indi == -1) indi = i;
            s.push({heights[i],indi});
        }
        while(!s.empty())
        {
            auto p = s.top();
            s.pop();
            int t = p.first*(heights.size() - p.second);
            maxi = max(maxi,t);
        }
        return maxi;
        
    }
};
