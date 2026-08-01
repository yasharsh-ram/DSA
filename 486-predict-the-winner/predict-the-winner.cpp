class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();int d[20][20]={};
        for(int i=0;i<n;i++){
            d[i][i]=nums[i];
        }
        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){
                int j=i+len-1;
                d[i][j]=max(nums[i]-d[i+1][j],nums[j]-d[i][j-1]);
            }
        }
        
        return d[0][n-1]>=0;
        
    }
};