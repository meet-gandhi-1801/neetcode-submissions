class Solution {
private:
    vector<pair<int,int>> d = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    void bfs(vector<vector<char>> &g,int x,int y)
    {
        g[x][y] = '0';      
        for(auto [dx,dy] : d)
        {
            int idx = x+dx;
            int idy = y+dy;

            if(idx < 0 || idy < 0 || idx == g.size() || idy == g[0].size() || g[idx][idy] != '1')
                continue;
            bfs(g,idx,idy);
        }  
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    bfs(grid,i,j);
                }
            }
        }
        return ans; 
    }
};