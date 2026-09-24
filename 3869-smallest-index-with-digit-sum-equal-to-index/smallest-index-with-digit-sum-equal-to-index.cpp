class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            // int x=nums[i];
            int digitsum=0;
            // while(x>0){
            //     digitsum+=x%10;
            //     x/=10;
            // }
            for(int x=nums[i];x>0;x/=10){
                digitsum+=x%10;
            }
                if(digitsum==i){
                    return i;
                }
            }
        
        return -1;
    }
};