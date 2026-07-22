class Solution {
    vector<int>ans;
    vector<pair<int,int>>arr;
    void merge(int left,int mid,int right){
        int i=left;
        int j=mid+1;
        vector<pair<int,int>>temp;
        int rightcount=0;
        while(i<=mid&&j<=right){
            if(arr[i].first<=arr[j].first){
                ans[arr[i].second]+=rightcount;
                temp.push_back(arr[i]);
                i++;
            }else{
                rightcount++;
                temp.push_back(arr[j]);
                j++;
            }
        }
        while(i<=mid){
             ans[arr[i].second]+=rightcount;
                temp.push_back(arr[i]);
                i++;
        }
        while(j<=right){
            temp.push_back(arr[j]);
            j++;
        }
        for(int k=left;k<=right;k++){
            arr[k]=temp[k-left];
        }
        
    }
    void mergesort(int left,int right){
        if(left>=right)return;
        int mid=left+(right-left)/2;
        mergesort(left,mid);
        mergesort(mid+1,right);
        merge(left,mid,right);

    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        ans.resize(n,0);
        for(int i=0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        mergesort(0,n-1);
        return ans;

        
    }
};

// vector<int> ans;
//         for (int i = 0; i < nums.size(); i++) {
//             int count = 0;
//             for (int j = i + 1; j < nums.size(); j++) {
//                 if (nums[j] < nums[i]) {
//                     count++;
//                 }
//             }
//             ans.push_back(count);
//         }
//         return ans;