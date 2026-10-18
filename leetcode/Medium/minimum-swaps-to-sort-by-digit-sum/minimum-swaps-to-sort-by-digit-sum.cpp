class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> hash;            // value -> current index
        vector<pair<int, int>> A(n);             // {digit sum, value}
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            int sum = 0;
            while (num > 0) sum += num % 10, num /= 10;   // digit sum
            A[i] = {sum, nums[i]};
            hash[nums[i]] = i;
        }
         sort(A.begin(), A.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) return a.second < b.second;
            else return a.first < b.first;
        });
        int swaps = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != A[i].second) { 
                swap(nums[i], nums[hash[A[i].second]]);
                
                swap(hash[nums[i]], hash[nums[hash[A[i].second]]]);
                ++swaps;                        
        }
        }
        return swaps;
    }
};
// hash[A[i].second] still holds j, so nums[j] is the OLD nums[i].
                // This swaps hash[target] (-> i) and hash[old] (-> j). Correct.
                 // index i is now fixed for good
            