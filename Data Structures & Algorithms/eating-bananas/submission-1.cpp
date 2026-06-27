class Solution {
public:
    bool solve(int mid,vector<int> &piles,int k)
    {
        int ans = 0;

        for(int n : piles)
        {
            ans += n/mid;
            
            if(n %mid != 0) ans++;


        }

        return  ans <= k;
    }
    int minEatingSpeed(vector<int>& piles, int k) {
        int l = 1;
        int h = 1e9;
        int ans = -1;

        while(l <= h)
        {
            int mid = (l + h) >> 1;

            if(solve(mid,piles,k))
            {
                ans = mid;
                h = mid-1;
            }
            else l = mid +1 ;
        }

        return ans;
        
    }
};
