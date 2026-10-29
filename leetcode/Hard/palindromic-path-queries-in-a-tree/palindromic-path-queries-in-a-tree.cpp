// #include <bits/stdc++.h>
// using namespace std;

class Solution {
    struct SegTree {
        int size;
        vector<array<int, 26>> tree;

        SegTree() : size(0) {}
        SegTree(int n) {
            size = 1;
            while (size < n) size <<= 1;
            tree.assign(2 * size, array<int, 26>{});
        }

        array<int, 26> merge(const array<int, 26>& a, const array<int, 26>& b) {
            array<int, 26> res{};
            for (int i = 0; i < 26; i++) res[i] = a[i] + b[i];
            return res;
        }

        void update(int idx, const array<int, 26>& val) {
            idx += size;
            tree[idx] = val;
            for (idx >>= 1; idx > 0; idx >>= 1)
                tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
        }

        array<int, 26> query(int l, int r) {
            l += size;
            r += size;
            array<int, 26> left{}, right{};
            while (l <= r) {
                if (l & 1) left = merge(left, tree[l++]);
                if (!(r & 1)) right = merge(tree[r--], right);
                l >>= 1;
                r >>= 1;
            }
            return merge(left, right);
        }
    };

    int n, curPos;
    string s;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, subtree;
    SegTree seg;

    int dfs(int v, int p) {
        parent[v] = p;
        subtree[v] = 1;
        int maxSize = 0;
        for (int u : adj[v]) {
            if (u == p) continue;
            depth[u] = depth[v] + 1;
            int size = dfs(u, v);
            subtree[v] += size;
            if (size > maxSize) {
                maxSize = size;
                heavy[v] = u;
            }
        }
        return subtree[v];
    }

    void decompose(int v, int h) {
        head[v] = h;
        pos[v] = curPos++;

        array<int, 26> freq{};
        freq[s[v] - 'a'] = 1;
        seg.update(pos[v], freq);

        if (heavy[v] != -1) decompose(heavy[v], h);

        for (int u : adj[v])
            if (u != parent[v] && u != heavy[v])
                decompose(u, u);
    }

    array<int, 26> queryPath(int a, int b) {
        array<int, 26> res{};
        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]]) swap(a, b);
            auto cur = seg.query(pos[head[a]], pos[a]);
            for (int i = 0; i < 26; i++) res[i] += cur[i];
            a = parent[head[a]];
        }
        if (depth[a] > depth[b]) swap(a, b);
        auto cur = seg.query(pos[a], pos[b]);
        for (int i = 0; i < 26; i++) res[i] += cur[i];
        return res;
    }

    void updateNode(int u, char c) {
        array<int, 26> freq{};
        freq[c - 'a'] = 1;
        seg.update(pos[u], freq);
        s[u] = c;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string str, vector<string>& queries) {
        this->n = n;
        s = str;

        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        subtree.assign(n, 0);
        curPos = 0;

        dfs(0, -1);

        seg = SegTree(n);
        decompose(0, 0);

        vector<bool> ans;
        for (auto& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int node;
                char val;
                ss >> node >> val;
                updateNode(node, val);
            } else {
                int u, v;
                ss >> u >> v;
                auto freq = queryPath(u, v);
                int odd = 0;
                for (int x : freq)
                    if (x % 2) odd++;
                ans.push_back(odd <= 1);
            }
        }
        return ans;
    }
};