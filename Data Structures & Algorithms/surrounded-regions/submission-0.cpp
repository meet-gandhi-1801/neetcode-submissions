class Solution {
   private:
    vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void bfs(vector<vector<char>>& g, int x, int y) {
        g[x][y] = '#';

        for (auto [dx, dy] : d) {
            int idx = x + dx;
            int idy = y + dy;

            if (idx < 0 || idy < 0 || idx == g.size() || idy == g[0].size() || g[idx][idy] != 'O')
                continue;
            bfs(g, idx, idy);
        }
    }

   public:
    void solve(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 'O') bfs(grid, i, 0);
            if (grid[i][m - 1] == 'O') bfs(grid, i, m - 1);
        }
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 'O') bfs(grid, 0, i);
            if (grid[n - 1][i] ==  'O') bfs(grid, n - 1, i);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#')
                    grid[i][j] = 'O';
                else if (grid[i][j] == 'O')
                    grid[i][j] = 'X';
            }
        }
    }
};
