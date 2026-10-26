class Solution {
      long long dfs(int x,int y,int m,int n,vector<vector<int>>& grid,vector<vector<bool>>& visit){
        if(x<0||x>=m||y<0||y>=n)return 0;
        if(grid[x][y]==0||visit[x][y])return 0;
        visit[x][y]=true;
        long long sum=grid[x][y];
        vector<int>dirx={0,1,0,-1};
        vector<int>diry={-1,0,1,0};
        for(int i=0;i<4;i++){
            int r=x+dirx[i];
            int c=y+diry[i];
            sum+=dfs(r,c,m,n,grid,visit);
        }
        return sum;
      }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visit(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0&&!visit[i][j]){
                    long long sum=dfs(i,j,m,n,grid,visit);
                    if(sum%k==0){
                    count++;
                    }
                }
            }
        }
        return count;
    }
};