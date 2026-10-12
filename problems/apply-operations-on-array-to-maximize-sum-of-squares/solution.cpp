class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD=1e9+7;
        vector<int>bitset(31,0);
        for(int i=0;i<nums.size();i++){
           for(int b=0;b<31;b++){
            if(nums[i]&(1<<b)){
                bitset[b]++;
            }
           }
        }
        long long result=0;
        for(int j=0;j<k;j++){
            long long x=0;
            for(int b=0;b<31;b++){
                if(bitset[b]>0){
                    x|=(1LL<<b);
                    bitset[b]--;
                }
            }
            result=(result+x*x)%MOD;
        }
        return result;
        
    }
};