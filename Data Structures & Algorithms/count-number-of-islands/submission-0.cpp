class Solution {
private:
    bool IsValid(int x,int y , int n, int m){
        return x>=0 && x<n && y>=0 && y<m;
    }
    void Dfs(vector<vector<char>> &grid, vector<vector<int>>& vis,int x, int y){
         if(vis[x][y])
                return ;
            vis[x][y]=1;
            if(IsValid(x+1,y,n,m) && grid[x+1][y]=='1')
                Dfs(grid,vis,x+1,y);
            if(IsValid(x,y+1,n,m) && grid[x][y+1]=='1')
                Dfs(grid,vis,x,y+1);
            if(IsValid(x-1,y,n,m) && grid[x-1][y]=='1')
                Dfs(grid,vis,x-1,y);
            if(IsValid(x,y-1,n,m) && grid[x][y-1]=='1')
                Dfs(grid,vis,x,y-1);
            
    }
public:
    int n ;
    int m ;
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int answer = 0,idx=0;
        for(int i =0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    Dfs(grid,vis,i,j);
                    answer++;
                }
            }
        }
        return answer;
    }
};