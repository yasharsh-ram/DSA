// class Solution {
// public:
//     int uniqueXorTriplets(vector<int>& nums) {
//         unordered_set<int>set;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i;j<nums.size();j++){
//                 for(int k=j;k<nums.size();k++){
//                     set.insert(nums[i]^nums[j]^nums[k]);
//                 }
//             }
//         }
//         return set.size();
//     }
// };
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)return n;
        int ans=1;
        while(ans<=n){
            ans<<=1;
        }
        return ans;
         }
};