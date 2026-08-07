class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<bool>visit(nums.size(),false);
        for(int n=0;n<nums.size();n++){
            if(visit[nums[n]]){
                return nums[n];
            }
            visit[nums[n]]=true;
        }
        return -1;
    }
};

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         if(nums.size()>1){
//             int slow=nums[0];
//             int fast=nums[nums[0]];
//             while(slow!=fast){
//                 slow=nums[slow];
//                 fast=nums[nums[fast]];
//             }
//             fast=0;
//             while(fast!=slow){
//                 slow=nums[slow];
//                 fast=nums[fast];
//             }
//             return slow;
//         }
//         return -1;
//     }
// };