// class Solution {
// public:
//     int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
//         int res=0;
//         for(int i=0;i<arr1.size();i++){
//             bool found=false;
//             for(int j=0;j<arr2.size();j++){
//                 if(abs(arr1[i]-arr2[j])<=d)found=true;
//             }
//             if(!found)res+=1;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int ans = 0, j = 0;

        for (int x : arr1) {
            while (j < arr2.size() && arr2[j] < x - d)
                j++;

            if (j == arr2.size() || arr2[j] > x + d)
                ans++;
        }

        return ans;
    }
};