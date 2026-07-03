class Solution {
   private:
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

   public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = true;

        while (!pq.empty()) {
            auto [time, p] = pq.top();
            auto [x, y] = p;
            pq.pop();

            if (x == n - 1 && y == n - 1) return time;

            for (auto [dx, dy] : dir) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

                if (vis[nx][ny]) continue;

                vis[nx][ny] = true;
                pq.push({max(time, grid[nx][ny]), {nx, ny}});
            }
        }
        return -1;
    }
};
