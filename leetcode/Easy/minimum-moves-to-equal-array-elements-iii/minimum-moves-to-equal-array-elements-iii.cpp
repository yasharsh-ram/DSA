class Solution {
public:
    int minMoves(vector<int>& nums) {
        int max=*max_element(nums.begin(),nums.end());
        int res=0;
        for(int x:nums){
            res+=max-x;
        }
        return res;
    }
};