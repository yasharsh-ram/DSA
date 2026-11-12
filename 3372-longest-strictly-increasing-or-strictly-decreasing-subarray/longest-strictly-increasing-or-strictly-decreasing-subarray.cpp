class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res=1;
        for(int i=0;i<nums.size();i++){
            int inc=1,dec=1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[j-1]){
                    dec++;
                    if(inc>1)break;
                }else if(nums[j]>nums[j-1]){
                    inc++;
                    if(dec>1)break;
                }else{
                    break;
                }
                res=max(res,max(inc,dec));
            }
        }
        return res;
    }
};