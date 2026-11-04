class Solution {
    multiset<int> left, right;
    long long sumleft=0;
    long long sumright=0;
    void rebalance(){
        int target=(left.size()+right.size()+1)/2;
        while(left.size()>target){
            int val=*left.rbegin();
            left.erase(left.find(val));
            sumleft-=val;
            right.insert(val);
            sumright+=val;
        }
        while(left.size()<target){
            int val=*right.begin();
            right.erase(right.find(val));
            sumright-=val;
            left.insert(val);
            sumleft+=val;
        }
    }
    void add(int num){
        if(left.empty()||num<=*left.rbegin()){
            left.insert(num);
            sumleft+=num;
        }else{
            right.insert(num);
            sumright+=num;
        }
        rebalance();
    }
    void remove(int num){
        auto it=left.find(num);
        if(it!=left.end()){
            sumleft-=num;
            left.erase(it);
        }else{
            it=right.find(num);
            sumright-=num;
            right.erase(it);
        }
        rebalance();
    }
    long long getcost(){
        long long median=*left.rbegin();
        return median*(long long)left.size()-sumleft+sumright-median*(long long)right.size();
    }
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n=nums.size();
        vector<long long>cost;
        for(int i=0;i<n;i++){
            add(nums[i]);
            if(i>=x){
                remove(nums[i-x]);
            }
            if(i>=x-1){
                cost.push_back(getcost());
            }
        }
        const long long INF = 1e18;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(i >=x && dp[i-x][j-1]!=INF){
                    dp[i][j]=min(dp[i][j],dp[i-x][j-1]+cost[i-x]);
                }
            }
        }
        return dp[n][k];
    }
};