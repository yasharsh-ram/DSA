class Solution {
    bool dfs(int x,int y,int m,int n,vector<vector<int>>& grid,vector<vector<bool>>& visit){
        if(x<0||x>=m||y<0||y>=n)return false;
        if(grid[x][y]==1||visit[x][y])return true;
        visit[x][y]=true;
        bool closed=true;
        int dirx[4]={0,1,0,-1};
        int diry[4]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int r=x+dirx[i];
            int c=y+diry[i];
            if(!dfs(r,c,m,n,grid,visit)){
                closed=false;
            }
        }
        return closed;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>>visit(m,vector<bool>(n,false));
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0&&!visit[i][j]&&dfs(i,j,m,n,grid,visit)){
                    count++;
                }
            }
        }
        return count;
    }
};