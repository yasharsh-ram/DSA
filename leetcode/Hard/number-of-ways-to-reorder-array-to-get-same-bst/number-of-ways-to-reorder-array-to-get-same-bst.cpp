class Solution {
    long long MOD=1e9+7;
    vector<vector<long long>>comb;
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        comb.assign(n, vector<long long>(n, 0));
        for(int i=0;i<n;i++){
            comb[i][0]=comb[i][i]=1;
            for(int j=1;j<i;j++){
                comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%MOD;
            }
        }
        return(dfs(nums)-1+MOD)%MOD;
    }
    long long dfs(vector<int>& nums){
        int m=nums.size();
        if(m<3)return 1;
        vector<int>left_nodes,right_nodes;
        for(int i=1;i<m;i++){
            if(nums[i]<nums[0]){
                left_nodes.push_back(nums[i]);
            }else{
                right_nodes.push_back(nums[i]);
            }
        }
        long long left_ways=dfs(left_nodes);
        long long right_ways=dfs(right_nodes);
        long long totalways=(left_ways*right_ways)%MOD;
        return (totalways*comb[m-1][left_nodes.size()])%MOD;
    }
};

    
    
