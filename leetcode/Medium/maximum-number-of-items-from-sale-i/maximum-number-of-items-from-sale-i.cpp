class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        int minprice=INT_MAX;
        vector<int>dp(budget+1,0);
        for(int i=0;i<n;i++){
            int factor=items[i][0];
            int price=items[i][1];
            minprice=min(minprice,price);
            int gain=0;
            for(int j=0;j<n;j++){
                if(items[j][0]%factor==0)gain++;
            }
        
            for(int j=budget;j>=price;j--){
                dp[j]=max(dp[j],dp[j-price]+gain);
            }
        }
            int ans=0;
            for(int i=0;i<=budget;i++){
                int extra=(budget-i)/minprice;
                ans=max(ans,dp[i]+extra);
            }
        return ans;
    }
};