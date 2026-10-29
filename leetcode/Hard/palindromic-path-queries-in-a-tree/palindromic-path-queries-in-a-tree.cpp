// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
//     struct SegTree {
//         int size;
//         vector<array<int, 26>> tree;

//         SegTree() : size(0) {}
//         SegTree(int n) {
//             size = 1;
//             while (size < n) size <<= 1;
//             tree.assign(2 * size, array<int, 26>{});
//         }

//         array<int, 26> merge(const array<int, 26>& a, const array<int, 26>& b) {
//             array<int, 26> res{};
//             for (int i = 0; i < 26; i++) res[i] = a[i] + b[i];
//             return res;
//         }

//         void update(int idx, const array<int, 26>& val) {
//             idx += size;
//             tree[idx] = val;
//             for (idx >>= 1; idx > 0; idx >>= 1)
//                 tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
//         }

//         array<int, 26> query(int l, int r) {
//             l += size;
//             r += size;
//             array<int, 26> left{}, right{};
//             while (l <= r) {
//                 if (l & 1) left = merge(left, tree[l++]);
//                 if (!(r & 1)) right = merge(tree[r--], right);
//                 l >>= 1;
//                 r >>= 1;
//             }
//             return merge(left, right);
//         }
//     };

//     int n, curPos;
//     string s;
//     vector<vector<int>> adj;
//     vector<int> parent, depth, heavy, head, pos, subtree;
//     SegTree seg;

//     int dfs(int v, int p) {
//         parent[v] = p;
//         subtree[v] = 1;
//         int maxSize = 0;
//         for (int u : adj[v]) {
//             if (u == p) continue;
//             depth[u] = depth[v] + 1;
//             int size = dfs(u, v);
//             subtree[v] += size;
//             if (size > maxSize) {
//                 maxSize = size;
//                 heavy[v] = u;
//             }
//         }
//         return subtree[v];
//     }

//     void decompose(int v, int h) {
//         head[v] = h;
//         pos[v] = curPos++;

//         array<int, 26> freq{};
//         freq[s[v] - 'a'] = 1;
//         seg.update(pos[v], freq);

//         if (heavy[v] != -1) decompose(heavy[v], h);

//         for (int u : adj[v])
//             if (u != parent[v] && u != heavy[v])
//                 decompose(u, u);
//     }

//     array<int, 26> queryPath(int a, int b) {
//         array<int, 26> res{};
//         while (head[a] != head[b]) {
//             if (depth[head[a]] < depth[head[b]]) swap(a, b);
//             auto cur = seg.query(pos[head[a]], pos[a]);
//             for (int i = 0; i < 26; i++) res[i] += cur[i];
//             a = parent[head[a]];
//         }
//         if (depth[a] > depth[b]) swap(a, b);
//         auto cur = seg.query(pos[a], pos[b]);
//         for (int i = 0; i < 26; i++) res[i] += cur[i];
//         return res;
//     }

//     void updateNode(int u, char c) {
//         array<int, 26> freq{};
//         freq[c - 'a'] = 1;
//         seg.update(pos[u], freq);
//         s[u] = c;
//     }

// public:
//     vector<bool> palindromePath(int n, vector<vector<int>>& edges, string str, vector<string>& queries) {
//         this->n = n;
//         s = str;

//         adj.assign(n, {});
//         for (auto& e : edges) {
//             adj[e[0]].push_back(e[1]);
//             adj[e[1]].push_back(e[0]);
//         }

//         parent.assign(n, -1);
//         depth.assign(n, 0);
//         heavy.assign(n, -1);
//         head.assign(n, 0);
//         pos.assign(n, 0);
//         subtree.assign(n, 0);
//         curPos = 0;

//         dfs(0, -1);

//         seg = SegTree(n);
//         decompose(0, 0);

//         vector<bool> ans;
//         for (auto& q : queries) {
//             stringstream ss(q);
//             string type;
//             ss >> type;

//             if (type == "update") {
//                 int node;
//                 char val;
//                 ss >> node >> val;
//                 updateNode(node, val);
//             } else {
//                 int u, v;
//                 ss >> u >> v;
//                 auto freq = queryPath(u, v);
//                 int odd = 0;
//                 for (int x : freq)
//                     if (x % 2) odd++;
//                 ans.push_back(odd <= 1);
//             }
//         }
//         return ans;
//     }
// };

class Solution {
    class ST {
    public:
        vector<int> seg;
        int n;

        ST(vector<int>& arr) {
            n = arr.size();
            seg.resize(4 * n);
            build(1, 0, n - 1, arr);
        }

        void build(int node, int l, int r, vector<int>& arr) {
            if (l == r) {
                seg[node] = arr[l];
                return;
            }

            int mid = (l + r) / 2;

            build(node * 2, l, mid, arr);
            build(node * 2 + 1, mid + 1, r, arr);

            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        }

        void update(int node, int l, int r, int idx, int val) {
            if (l == r) {
                seg[node] = val;
                return;
            }

            int mid = (l + r) / 2;

            if (idx <= mid) {
                update(node * 2, l, mid, idx, val);
            } else {
                update(node * 2 + 1, mid + 1, r, idx, val);
            }

            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        }

        int query(int node, int l, int r, int ql, int qr) {
            if (qr < l || r < ql) return 0;

            if (ql <= l && r <= qr) {
                return seg[node];
            }

            int mid = (l + r) / 2;

            int left = query(node * 2, l, mid, ql, qr);
            int right = query(node * 2 + 1, mid + 1, r, ql, qr);

            return left ^ right;
        }
    };

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 1: Find parent and depth using BFS
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }

        // Step 2: Find subtree sizes and heavy children
        vector<int> sz(n, 1);
        vector<int> heavy(n, -1);

        function<void(int)> dfs1 = [&](int u) {
            int largest = 0;

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                dfs1(v);
                sz[u] += sz[v];

                if (sz[v] > largest) {
                    largest = sz[v];
                    heavy[u] = v;
                }
            }
        };

        dfs1(0);

        // Step 3: Build heavy chains and flattened positions
        vector<int> head(n);
        vector<int> pos(n);
        int current = 0;

        function<void(int, int)> dfs2 = [&](int u, int h) {
            head[u] = h;
            pos[u] = current++;

            if (heavy[u] != -1) {
                dfs2(heavy[u], h);
            }

            for (int v : adj[u]) {
                if (v == parent[u] || v == heavy[u]) continue;

                dfs2(v, v);
            }
        };

        dfs2(0, 0);

        // Step 4: Convert characters into bitmasks
        vector<int> masks(n);

        for (int u = 0; u < n; u++) {
            masks[pos[u]] = 1 << (s[u] - 'a');
        }

        ST st(masks);

        // Step 5: Get XOR mask along a path
        auto pathXor = [&](int u, int v) {
            int ans = 0;

            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]]) {
                    swap(u, v);
                }

                ans ^= st.query(
                    1, 0, n - 1,
                    pos[head[u]], pos[u]
                );

                u = parent[head[u]];
            }

            if (depth[u] > depth[v]) {
                swap(u, v);
            }

            ans ^= st.query(
                1, 0, n - 1,
                pos[u], pos[v]
            );

            return ans;
        };

        // Step 6: Process queries
        vector<bool> result;

        for (auto& query : queries) {
            stringstream ss(query);
            string type, a, b;

            ss >> type >> a >> b;

            if (type == "update") {
                int u = stoi(a);
                char c = b[0];

                s[u] = c;

                int newMask = 1 << (c - 'a');

                st.update(
                    1, 0, n - 1,
                    pos[u], newMask
                );
            } else {
                int u = stoi(a);
                int v = stoi(b);

                int mask = pathXor(u, v);

                // True if at most one character has odd frequency
                result.push_back(
                    (mask & (mask - 1)) == 0
                );
            }
        }

        return result;
    }
};