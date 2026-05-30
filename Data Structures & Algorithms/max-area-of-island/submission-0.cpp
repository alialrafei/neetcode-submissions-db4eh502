class Solution {
private:
    bool IsValid(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    int Dfs(vector<vector<int>>& grid, vector<vector<bool>>& vis, int x,
            int y) {
        if (vis[x][y])
            return 0;
        vis[x][y] = true;
        int area = 1;
        if (IsValid(x + 1, y, n, m) && grid[x + 1][y] == 1)
            area+=Dfs(grid, vis, x + 1, y);
        if (IsValid(x, y + 1, n, m) && grid[x][y + 1] == 1)
            area+=Dfs(grid, vis, x, y + 1);
        if (IsValid(x - 1, y, n, m) && grid[x - 1][y] == 1)
            area+=Dfs(grid, vis, x - 1, y);
        if (IsValid(x, y - 1, n, m) && grid[x][y - 1] == 1)
            area+=Dfs(grid, vis, x, y - 1);
        return area;
    }

public:
    int n;
    int m;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int area = 0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    area = max(area,Dfs(grid,vis,i,j));
                  
                }
            }
        }
        return area;

    }
};