// class Solution {
// public:
//     int sortPermutation(vector<int>& nums) {
//         int res = 0;
//         bool first = true;
//         for (int i = 0; i < nums.size(); i++) {
//             if(nums[i]==i)continue;
//             if (first) {
//                 res = nums[i];
//                 first =false;
//             } else {
//                 res &= nums[i];
//             }
//         }
//         return res;
//     }
// };
class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int res = -1;          // all bits set
        bool any = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i) {
                res &= nums[i];
                any = true;
            }
        }
        return any ? res : 0;
    }
};