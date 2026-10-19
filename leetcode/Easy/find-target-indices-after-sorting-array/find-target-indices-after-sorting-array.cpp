// class Solution {
// public:
//     vector<int> targetIndices(vector<int>& nums, int target) {
//         vector<int>ans;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<nums.size();i++){
//             if(nums[i]==target){
//                 ans.push_back(i);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int cnt1=0,cnt2=0;
        for(int x:nums){
            if(x<target)cnt1+=1;
            else if(x==target)cnt2+=1;
        }
        vector<int>ans;
        for(int i=0;i<cnt2;i++){
            ans.push_back(cnt1+i);
        }
        return ans;
    }
};
