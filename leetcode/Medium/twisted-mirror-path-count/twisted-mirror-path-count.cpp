class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD=1e9+7;
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dp(m,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=0,prev=0;j<m;j++){
                if(grid[i][j]==1){
                    swap(prev,dp[j]);
                }else{
                    dp[j]=prev=(prev+dp[j])%MOD;
                }
            }
        }
        return dp[m-1];
    }
};

// class Solution {
// public:
//     int uniquePaths(vector<vector<int>>& grid) {
//         const int MOD=1e9+7;
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>>dp(n,vector<int>(m,0));
//         dp[0][0]=1;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1){
//                     int up=dp[i][j];
//                     int left=dp[i][j];
//                     dp[i][j]=0;
//                     if(i+1<n)dp[i+1][j]=(dp[i+1][j]+up)%MOD;
//                     if(j+1<m)dp[i][j+1]=(dp[i][j+1]+left)%MOD;
//                 }else{
//                     if(i+1<n)dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;
//                     if(j+1<m)dp[i][j+1]=(dp[i][j+1]+dp[i][j])%MOD;
//                 }
//             }
//         }
//         return dp[n-1][m-1];
//     }
// };

// class Solution {
//     int n,m;
//     const int MOD=1e9+7;
//     vector<vector<int>>dp;
//     int dfs(int i,int j,vector<vector<int>>& grid){
//             if(i>=n||j>=m)return 0;
//             if(i==n-1&&j==m-1)return 1;
//             if(dp[i][j]!=-1)return dp[i][j];
//             int right=0,down=0;
//             int x=i,y=j+1;
//             if(y<m&&grid[x][y]==1)
//             x++;
//             right=dfs(x,y,grid);
//             x=i+1,y=j;
//             if(x<n&&grid[x][y]==1)
//             y++;
//             down=dfs(x,y,grid);
//             return dp[i][j]=(right+down)%MOD;
//         }
// public:
//     int uniquePaths(vector<vector<int>>& grid) {
//         n=grid.size();
//         m=grid[0].size();
//         dp.assign(n, vector<int>(m, -1));
//         return dfs(0,0,grid);
//     }
// };