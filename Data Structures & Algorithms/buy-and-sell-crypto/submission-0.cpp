class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0],maxi = 0;
        for(int n : prices)
        {
            maxi = max(maxi,n-mini);
            mini = min(mini,n);
        }
        return maxi;
        
    }
};
