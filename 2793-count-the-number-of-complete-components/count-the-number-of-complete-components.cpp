const int MAXN = 100005;
const int MAXE = 200005;

class Solution {
    int head[MAXN];
    int to[MAXE];
    int nxt[MAXE];
    bool visited[MAXN];
    int idx = 0;

    void addedge(int u, int v) {
        to[idx] = v;
        nxt[idx] = head[u];
        head[u] = idx;
        idx++;
    }

    void dfs(int node, int& nodes, int& edgesum) {
        visited[node] = true;
        nodes++;
        for (int i = head[node]; i != -1; i = nxt[i]) {
            edgesum++;
            int neigh = to[i];
            if (!visited[neigh]) {
                dfs(neigh, nodes, edgesum);
            }
        }
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        memset(head, -1, sizeof(head));
        memset(visited, false, sizeof(visited));
        idx = 0;
        int edgesum = 0;
        int nodes = 0;
        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            addedge(u, v);
            addedge(v, u);
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int nodes = 0;
                int edgesum = 0;
                dfs(i, nodes, edgesum);
                // int eed=edges/2;
                if (edgesum / 2 == nodes * (nodes - 1) / 2) {
                    ans++;
                }
            }
        }
        return ans;
    }
};