class Solution {
private:
      vector<pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int,int>> q;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 2) q.push({i,j});
            }
        }
        while(!q.empty())
        {
            int k = q.size();
            bool aaloo = false;
            while(k--)
            {
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy] : d)
                {int idx = x+ dx;
                int idy = y + dy;
                    if(idx < 0 || idy < 0 || idx == grid.size() || idy == grid[0].size() || grid[idx][idy] != 1)
                continue;
                    aaloo = true;
                    grid[idx][idy] = 2;
                    q.push({idx,idy});
                }

            }
            if (aaloo)ans++;
        }
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1) return -1; 
            }
        }
        return  ans;
    }
};
