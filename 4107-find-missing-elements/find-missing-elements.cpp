class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>ans;
        int low=nums[0];
        int high=nums[n-1];
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]];
        }
        for(int i=low;i<high;i++){
            if(mpp.find(i)==mpp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};