// class Solution {
// public:
//     int minOperations(vector<int>& nums) {
//         int n=nums.size();
//         int ans=INT_MAX;
//         for(int rev=0;rev<2;rev++){
//             vector<int>arr=nums;
//             if(rev==1){
//                 reverse(arr.begin(),arr.end());
//             }
//             for(int k=0;k<n;k++){
//                 bool sorted=true;
//                 for(int i=0;i<n;i++){
//                     if(arr[(i+k)%n]!=i){
//                         sorted=false;
//                         break;
//                     }
//                 }
//                 if(sorted){
//                     ans=min(ans,k+rev);
//                 }
//             }
//         }
//         return ans==INT_MAX?-1:ans;
//     }
// };

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int start=distance(nums.begin(),find(nums.begin(),nums.end(),0));
        bool asc=true,desc=true;
        for(int i=1;i<n;i++){
            int value=nums[(start+i)%n];
            if(value!=i)asc=false;
            if(value!=n-i)desc=false;
            if(!asc&&!desc)return -1;
        }
        if(asc)return min(start,n-start+2);
        return min(n-start,start+2);
    }
};