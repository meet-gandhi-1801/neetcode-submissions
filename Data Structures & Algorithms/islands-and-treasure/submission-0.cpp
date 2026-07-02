const int l = INT_MAX;
class Solution {
public:
    vector<pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<
    pair<int, pair<int,int>>,
    vector<pair<int, pair<int,int>>>,
    greater<>
> pq;

        for(int i = 0;i<n;i++)
        {   
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    pq.push({0,{i,j}});
                }
            }
        }

        while(!pq.empty())
        {
            auto p = pq.top();
            pq.pop();
            int dist = p.first;
            int x = p.second.first;
            int y = p.second.second;

            for(auto [dx,dy] : d)
            {
                int idx = x+dx;
                int idy = y+dy;
                if(idx < 0 || idy < 0 || idx == n || idy == m || grid[idx][idy] == -1)
                    continue;
                if(grid[idx][idy] == INT_MAX)
                {
                    grid[idx][idy] = dist + 1;
                    pq.push({dist + 1,{idx,idy}});
                }
            }
        }
    }
};
