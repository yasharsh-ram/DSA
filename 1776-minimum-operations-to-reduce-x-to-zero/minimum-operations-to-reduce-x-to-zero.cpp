class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        int target=total-x;
        int curr=0;
        int maxi=-1;
        int left=0;
        for(int right=0;right<nums.size();right++){
            curr+=nums[right];
            while(left<=right&&curr>target){
                curr-=nums[left];
                left++;
            }
            if(curr==target){
                maxi=max(maxi,right-left+1);
            }
        }
        if(maxi==-1)return -1;
        return nums.size()-maxi;
        
    }
};