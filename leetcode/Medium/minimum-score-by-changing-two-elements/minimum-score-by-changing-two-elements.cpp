// class Solution {
// public:
//     int minimizeSum(vector<int>& nums) {
//         int n=nums.size();
//         sort(nums.begin(),nums.end());
//         return min({nums[n-1]-nums[2],nums[n-2]-nums[1],nums[n-3]-nums[0]});
//     }
// };

class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int mn1 = INT_MAX, mn2 = INT_MAX, mn3 = INT_MAX;
        int mx1 = INT_MIN, mx2 = INT_MIN, mx3 = INT_MIN;

        for (int x : nums) {

            // Three smallest
            if (x < mn1) {
                mn3 = mn2;
                mn2 = mn1;
                mn1 = x;
            }
            else if (x < mn2) {
                mn3 = mn2;
                mn2 = x;
            }
            else if (x < mn3) {
                mn3 = x;
            }

            // Three largest
            if (x > mx1) {
                mx3 = mx2;
                mx2 = mx1;
                mx1 = x;
            }
            else if (x > mx2) {
                mx3 = mx2;
                mx2 = x;
            }
            else if (x > mx3) {
                mx3 = x;
            }
        }

        return min({
            mx1 - mn3,
            mx2 - mn2,
            mx3 - mn1
        });
    }
};