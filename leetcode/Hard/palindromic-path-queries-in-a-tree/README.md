# [Palindromic Path Queries in a Tree](https://leetcode.com/problems/palindromic-path-queries-in-a-tree/)

## Metadata
- **Difficulty:** <span style="color: #ef4444; font-weight: bold;">Hard</span>
- **Languages:** `C++`
- **Submission Date:** October 29, 2026
- **Tags:** `Array`, `String`, `Divide and Conquer`, `Bit Manipulation`, `Tree`, `Depth-First Search`, `Binary Indexed Tree`, `Segment Tree`

## Description
You are given an undirected tree with `n` nodes labeled 0 to `n - 1`. This is represented by a 2D array `edges` of length `n - 1`, where `edges[i] = [u_i, v_i]` indicates an undirected edge between nodes `u_i` and `v_i`.

You are also given a string `s` of length `n` consisting of lowercase English letters, where `s[i]` represents the character assigned to node `i`.

You are also given a string array `queries`, where each `queries[i]` is either:

	- `"update u_i c"`: Change the character at node `u_i` to `c`. Formally, update `s[u_i] = c`.

	- `"query u_i v_i"`: Determine whether the string formed by the characters on the **unique** path from `u_i` to `v_i` (inclusive) can be **rearranged** into a **palindrome**.

Return a boolean array `answer`, where `answer[j]` is `true` if the `j^th` query of type `"query u_i v_i"​​​​​​​` can be rearranged into a **palindrome**, and `false` otherwise.

 

**Example 1:**

**Input:** n = 3, edges = [[0,1],[1,2]], s = "aac", queries = ["query 0 2","update 1 b","query 0 2"]

**Output:** [true,false]

**Explanation:**

	- `"query 0 2"`: Path `0 &rarr; 1 &rarr; 2` gives `"aac"`, which can be rearranged to form `"aca"`, a palindrome. Thus, `answer[0] = true`.

	- `"update 1 b"`: Update node 1 to `&#39;b&#39;`, now `s = "abc"`.

	- `"query 0 2"`: Path characters are `"abc"`, which cannot be rearranged to form a palindrome. Thus, `answer[1] = false`.

Thus, `answer = [true, false]`.

**Example 2:**

**Input:** n = 4, edges = [[0,1],[0,2],[0,3]], s = "abca", queries = ["query 1 2","update 0 b","query 2 3","update 3 a","query 1 3"]

**Output:** [false,false,true]

**Explanation:**

	- `"query 1 2"`: Path `1 &rarr; 0 &rarr; 2` gives `"bac"`, which cannot be rearranged to form a palindrome. Thus, `answer[0] = false`.

	- `"update 0 b"`: Update node 0 to `&#39;b&#39;`, now `s = "bbca"`.

	- `"query 2 3"`: Path `2 &rarr; 0 &rarr; 3` gives `"cba"`, which cannot be rearranged to form a palindrome. Thus, `answer[1] = false`.

	- `"update 3 a"`: Update node 3 to `&#39;a&#39;`, `s = "bbca"`.

	- `"query 1 3"`: Path `1 &rarr; 0 &rarr; 3` gives `"bba"`, which can be rearranged to form `"bab"`, a palindrome. Thus, `answer[2] = true`.

Thus, `answer = [false, false, true]`.

 

**Constraints:**

	- `1 `1

## Solution

### C++
```cpp
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
```

---
*Autogenerated by [CodeSync](https://github.com/pardeep1916P/codeSync).*
