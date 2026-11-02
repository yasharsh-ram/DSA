class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res=0;
        for(int i=0;i<nums.size();i++){
            int mid=nums[nums.size()/2];
            res+=abs(nums[i]-mid);
        }
        return res;
    }
};