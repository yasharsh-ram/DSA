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