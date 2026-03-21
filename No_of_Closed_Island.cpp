class Solution {
public:
    int n,m;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    void dfs(int x,int y,vector<vector<int>>& grid, vector<vector<bool>> &visited){
        if(grid[x][y]==1 || visited[x][y]) return;
        visited[x][y]=1;

        for(auto &d:dir){
            int nx=x+d[0];
            int ny=y+d[1];
            if(nx>=0 && nx<n && ny>=0 && ny<m &&grid[nx][ny]==0 && !visited[nx][ny]){
                dfs(nx,ny,grid,visited);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int cnt=0;
        vector<vector<bool>> visited(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){
                    if(grid[i][j]==0 && !visited[i][j])
                    dfs(i,j,grid,visited);
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    cnt++;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return cnt;
    }
};
