class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> cost(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cost[i] = costs[i - 1];
        }
        const int INF = 1e9;
        vector<int> dp(n + 1, INF);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            if(i==1){
            dp[i]=dp[0]+cost[i]+1*1;
            }else if(i==2){
                dp[i]=min(dp[i-1]+cost[i]+1*1,dp[i-2]+cost[i]+2*2);
            }else{
                dp[i]=min({dp[i-1]+cost[i]+1*1,
                dp[i-2]+cost[i]+2*2,
                dp[i-3]+cost[i]+3*3});
            }
        }
        return dp[n];
    }
};