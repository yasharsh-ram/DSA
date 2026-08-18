class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(52);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }
        if (k == 1) {
            int ans = -1;
            for (int i = 0; i <= 50; i++) {
                if (freq[i] == 1) {
                    ans = max(ans, i);
                }
            }
            return ans;
        }
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        if (freq[nums[0]] == 1 && freq[nums[n - 1]] == 1) {
            return max(nums[0], nums[n - 1]);
        } else if (freq[nums[0]] == 1) {
            return nums[0];
        } else if (freq[nums[n - 1]] == 1) {
            return nums[n - 1];
        } else {
            return -1;
        }
    }
};