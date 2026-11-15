// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {
//         int n=arr.size();
//         int count=0;
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum+=arr[j];
//                 if(sum%2==1){
//                     count++;
//                 }
//             }
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int count=0;
        int even=1;
        int odd=0;
        int sum=0;
        const int MOD=1e9+7;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2!=0){
                count=count+even;
                odd++;
            }else{
                count=count+odd;
                even++;
            }
            count=count%MOD;
        }
        return count;
    }
};