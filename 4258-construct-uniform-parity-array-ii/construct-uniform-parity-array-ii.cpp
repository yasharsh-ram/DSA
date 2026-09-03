// class Solution {
// public:
//     bool uniformArray(vector<int>& nums1) {
//            int n=nums1.size();
//            int smalod=INT_MAX;
//            for(int i=0;i<n;i++){
//             if(nums1[i]%2!=0){
//                 smalod=min(smalod,nums1[i]);
//             }
//            }
//            if(smalod==INT_MAX)return true;
//            for(int i=0;i<n;i++){
//             if(nums1[i]<smalod&&nums1[i]%2==0)
//                 return false;
//            }
//            return true;
//     }
// };

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
           int smalod=INT_MAX;
           int smalevn=INT_MAX;
           for(int i=0;i<n;i++){
            if(nums1[i]%2!=0){
                smalod=min(smalod,nums1[i]);
            }else{
            smalevn=min(smalevn,nums1[i]);
           }
           }
           if(smalod==INT_MAX||smalevn==INT_MAX)return true;
           return smalod<smalevn;
    }
};
           