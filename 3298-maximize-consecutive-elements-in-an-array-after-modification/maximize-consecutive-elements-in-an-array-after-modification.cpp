class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxe=*max_element(nums.begin(),nums.end());
        vector<int>dp(maxe+2,0);
        for(int x:nums){
            dp[x+1]=max(dp[x+1],dp[x]+1);
            dp[x]=max(dp[x],dp[x-1]+1);
        }
        return *max_element(dp.begin(),dp.end());
    }
};