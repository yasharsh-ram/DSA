class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long>prefixGcd(n);
        int mx=nums[0];
        for(int i=0;i<n;i++){
            mx=max(mx,nums[i]);
            prefixGcd[i]=gcd(nums[i],mx);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int left=0;
        int right=prefixGcd.size()-1;
        long long ans=0;
        while(left<right){
            ans+=gcd(prefixGcd[left],prefixGcd[right]);
            left++;
            right--;
        }
        return ans;
        
    }
};