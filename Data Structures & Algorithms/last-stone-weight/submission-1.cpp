class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // if(stones.size() == 2)
        // {
        //     return abs(stones[0] - stones[1]);
        // }
        priority_queue<int> pq;
        for(int n : stones){
            pq.push(n);
        }
        while(pq.size() > 1)
        {
            int x = pq.top();pq.pop();
            int y = pq.top();pq.pop();
            if(x==0) return y;
            else if (y==0) return x;
            else{
            if(x!=y) pq.push(abs(x-y));
            else pq.push(0);}
            
        }
        return pq.top();
    }
};