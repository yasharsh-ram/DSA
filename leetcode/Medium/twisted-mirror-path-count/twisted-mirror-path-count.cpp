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