// class Solution {
// public:
//     int minCost(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         vector<vector<set<int>>> dp(m, vector<set<int>>(n));
//         dp[0][0].insert(grid[0][0]);
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (i == 0 && j == 0)
//                     continue;
//                 set<int> cs;
//                 int curr = grid[i][j];
//                 if (i == 0) {
//                     for (int x : dp[i][j - 1]) {
//                         cs.insert(x ^ curr);
//                     }
//                 } else if (j == 0) {
//                     for (int x : dp[i - 1][j]) {
//                         cs.insert(x ^ curr);
//                     }
//                 } else {
//                     for (int x : dp[i][j - 1]) {
//                         cs.insert(x ^ curr);
//                     }
//                     for (int x : dp[i - 1][j]) {
//                         cs.insert(x ^ curr);
//                     }
//                 }
//                 dp[i][j] = move(cs);
//             }
//         }
//         return *min_element(dp[m - 1][n - 1].begin(), dp[m - 1][n - 1].end());
//     }
// };

class Solution {
    int m,n;
    vector<vector<vector<int>>> dp;
    int dfs(int i,int j,int temp,vector<vector<int>>& grid){
        if(i>=m||j>=n)return INT_MAX;
        temp^=grid[i][j];
        if(i==m-1&&j==n-1)return temp;
        if(dp[i][j][temp]!=-1)return dp[i][j][temp];
        int right=dfs(i+1,j,temp,grid);
        int down=dfs(i,j+1,temp,grid);
        return dp[i][j][temp]=min(right,down);
    }
public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(1024, -1)));
        return dfs(0,0,0,grid);
    }
};