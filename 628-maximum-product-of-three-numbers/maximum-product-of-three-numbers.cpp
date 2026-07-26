class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int op1=nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        int op2=nums[0]*nums[1]*nums[nums.size()-1];
    
    return max(op1,op2);
    }
};