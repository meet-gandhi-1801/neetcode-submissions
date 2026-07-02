class Solution {
private:

    vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
public:
    bool isSafe(vector<vector<char>> &grid,int x,int y)
    {
        
if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()) return false;
else return true;
    }
    bool solve(vector<vector<char>>& grid, string word,int i,int x,int y,vector<vector<bool>> &vis) {
        if(i == word.size()) return true;
        vis[x][y] = true;
        
        for(auto [dx,dy] : dir)
        {
            if( isSafe(grid,x+dx,y+dy) && !vis[x+dx][y+dy] && grid[x+dx][y+dy] == word[i])
            {
                if(solve(grid,word,i+1,x+dx,y+dy,vis))
    return true;
            }
        }
        vis[x][y] = false;

        return false;
        

    }
    bool exist(vector<vector<char>>& grid, string word) {
vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == word[0])
                {
                    if(solve(grid,word,1,i,j,vis)) return true;
                }
            }
        }
        return false;
    }
};
