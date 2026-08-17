class Solution {
public:
    vector<int> prefix;
    vector<vector<int>> dp;
    int dfs(int l, int r) {
        if (l == r)
            return 0;
        if (dp[l][r] != -1)
            return dp[l][r];
        int ans = 0;
        for (int k = l; k < r; k++) {
            int leftsum = prefix[k + 1] - prefix[l];
            int rightsum = prefix[r + 1] - prefix[k + 1];
            if (leftsum < rightsum) {
                ans = max(ans, leftsum + dfs(l, k));
            } else if (leftsum > rightsum) {
                ans = max(ans, rightsum + dfs(k + 1, r));
            } else {
                ans = max(leftsum + dfs(l, k), rightsum + dfs(k + 1, r));
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
        dp.assign(n, vector<int>(n, -1));
        return dfs(0, n - 1);
    }
};