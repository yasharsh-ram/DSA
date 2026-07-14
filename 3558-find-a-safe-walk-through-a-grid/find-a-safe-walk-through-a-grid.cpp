class Solution {
    vector<vector<bool>> visited;
    vector<vector<int>> bestheal;
    vector<vector<int>> grid;
    int m, n;
    bool dfs(int i, int j, int health) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return false;
        if (visited[i][j])
            return false;
        if (grid[i][j] == 1) {
            health--;
        }
        if (health <= 0)
            return false;
        if (health <= bestheal[i][j])
            return false;
        bestheal[i][j] = health;
        if (i == m - 1 && j == n - 1)
            return true;
        visited[i][j] = true;
        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int nr = i + dr[k];
            int nc = j + dc[k];
            if (dfs(nr, nc, health)) {
                return true;
            }
        }
        visited[i][j] = false;
        return false;
    }

public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        bestheal = vector<vector<int>>(m, vector<int>(n, -1));
        return dfs(0, 0, health);
    }
};