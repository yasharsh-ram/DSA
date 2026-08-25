class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        vector<bool> pos(101, false);
        for (int i = 0; i < nums.size(); i++) {
            pos[nums[i]] = true;
        }
        int ans=k;
        while(ans<101&&pos[ans]){
            ans+=k;
        }
        
        return ans;
    }
};