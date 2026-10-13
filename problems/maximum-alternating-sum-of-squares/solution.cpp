class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long>sq;
        for(int x:nums){
            sq.push_back(1LL*x*x);
        }
        long long ans=0;
        sort(sq.begin(),sq.end());
        int i=0;
        int j=sq.size()-1;
        while(i<j){
            ans+=sq[j]-sq[i];
            i++;
            j--;
        }
        if(i==j){
            ans+=sq[i];
        }
        
        return ans;
    }
};