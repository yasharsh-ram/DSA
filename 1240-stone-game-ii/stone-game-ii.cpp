class Solution {
public:
int n;
vector<int>suffix;
vector<vector<int>>dp;
int solve(int i,int M,vector<int>&piles){
    if(i>=n)return 0;
    if(2*M>=n-i)return suffix[i];
    if(dp[i][M]!=-1)return dp[i][M];
    int ans=0;
    for(int x=1;x<=2*M;x++){
        int tak=suffix[i]-suffix[i+x];
        int nxtM=max(M,x);
        int opp=solve(i+x,nxtM,piles);
        int curr=tak+(suffix[i+x]-opp);
        ans=max(ans,curr);
    }
    return dp[i][M]=ans;
}
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        suffix.resize(n+1,0);
        for(int i=n-1;i>=0;i--){
            suffix[i]=piles[i]+suffix[i+1];
        }
        dp.assign(n,vector<int>(n+1,-1));
        return solve(0,1,piles);
        
    }
};