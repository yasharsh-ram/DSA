class Solution {
public:
    bool solve(int i, int j, int balance, vector<vector<char>>& grid,
               vector<vector<vector<int>>>& dp) {
                if(grid[i][j]=='('){
                    balance++;
                }else{
                    balance--;
                }
                if(balance<0)return false;
                if(i==grid.size()-1&&j==grid[0].size()-1)return balance==0;
                int remain=(grid.size()-i)+(grid[0].size()-j)-1;
                if(balance>remain)return false;
                if(dp[i][j][balance]!=-1){
                    return dp[i][j][balance];
                }
                bool down=false;
                bool right=false;
                if(i+1<grid.size()){
                    down=solve(i+1,j,balance,grid,dp);
                }
                if(j+1<grid[0].size()){
                    right=solve(i,j+1,balance,grid,dp);
                }
                return dp[i][j][balance]=(down||right);        
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        if((n+m-1)%2==1)return false;
        if(grid[0][0]!='('||grid[n-1][m-1]!=')')return false;
        vector<vector<vector<int>>> dp(
        n, vector<vector<int>>(m, vector<int>(n+m, -1)));
        return solve(0,0,0,grid,dp);
    }
};