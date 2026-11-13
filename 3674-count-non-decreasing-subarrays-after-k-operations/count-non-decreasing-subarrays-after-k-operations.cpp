// class Solution {
// public:
//     long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
//         int count = 0;
//         for (int i = 0; i < nums.size(); i++) {
//             int op = 0;
//             int maxs = nums[i];
//             for (int j = i; j < nums.size(); j++) {
//                 if (nums[j] < maxs) {
//                     op += maxs - nums[j];
//                 } else {
//                     maxs = nums[j];
//                 }
//                 if (op <= k) {
//                     count++;
//                 } else {
//                     break;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        long long count=0;
        long long ans=0;
        int n=nums.size();
        int j=n-1;
        deque<pair<int,int>>dq;
        for(int i=n-1;i>=0;i--){
            int grps=1;
            while(!dq.empty()&&dq.front().first<=nums[i]){
                count+=1LL*(nums[i]-dq.front().first)*dq.front().second;
                grps+=dq.front().second;
                dq.pop_front();
            }
            dq.push_front({nums[i],grps});
            while(count>k){
                count-=dq.back().first-nums[j];
                dq.back().second--;
                if(dq.back().second==0){
                dq.pop_back();
                }
                j--;
            }
        ans+=j-i+1;
        }
    
    return ans;
    }
};
