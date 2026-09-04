// class Solution {
// public:
//     int firstStableIndex(vector<int>& nums, int k) {
//         for(int i=0;i<nums.size();i++){
//             int mx=*max_element(nums.begin(),nums.begin()+i+1);
//             int mn=*min_element(nums.begin()+i,nums.end());
//             if(mx-mn<=k)return i;
//         }
//         return -1;
//     }
// };

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>premx(n);
        vector<int>premn(n);
        premx[0]=nums[0];
        for(int i=1;i<n;i++){
            premx[i]=max(premx[i-1],nums[i]);
        }
        premn[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            premn[i]=min(premn[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(premx[i]-premn[i]<=k)return i;
        }
        return -1;
    }
};