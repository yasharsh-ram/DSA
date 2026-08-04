class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // int n=nums.size();
        vector<int>ans;
        int low=*min_element(nums.begin(),nums.end());
        int high=*max_element(nums.begin(),nums.end());
        // unordered_map<int,int>mpp;
        // for(int i=0;i<n;i++){
        //     mpp[nums[i]];
        // }
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i=low+1;i<high;i++){
            // if(mpp.find(i)==mpp.end()){
            //     ans.push_back(i);
            // }
            if(!st.count(i)){
                ans.push_back(i);

            }
        }
        return ans;
    }
};