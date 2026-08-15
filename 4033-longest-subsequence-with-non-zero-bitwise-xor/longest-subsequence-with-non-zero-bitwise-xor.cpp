class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int totalxor=0;
        bool nonzero=false;
        for(int i=0;i<n;i++){
            totalxor=totalxor^nums[i];
            if(nums[i]!=0)nonzero=true;
        }
            if(totalxor!=0){
                return n;
            }
            if(nonzero){
                return n-1;
            }
        
        return 0;
        
    }
};