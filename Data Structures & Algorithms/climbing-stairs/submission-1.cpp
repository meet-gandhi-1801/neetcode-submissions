class Solution {
public:
    int solve(int n , vector<int> &dp)
    {
        if(n==1 || n == 0) return 1;
        if(dp[n] != INT_MAX) return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,INT_MAX);

        return solve(n,dp);
        
    }
};
