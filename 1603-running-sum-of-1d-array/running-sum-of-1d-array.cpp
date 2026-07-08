class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        for(int i=0;i<n;i++){
             prefix[i+1]=prefix[i]+nums[i];
        }
        vector<int>ans;
        for(int i=1;i<=n;i++){
        ans.push_back(prefix[i]);
        }
         return ans;
    }
};