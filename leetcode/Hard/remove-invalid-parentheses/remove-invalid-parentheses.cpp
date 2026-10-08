class Solution {
public:
    vector<string> ans;

    void dfs(string &s, int idx, int left, int right,
             int open, string &curr) {

        if (idx == s.length()) {
            if (left == 0 && right == 0 && open == 0) {
                ans.push_back(curr);
            }
            return;
        }

       
        if (s[idx] == '(' && left > 0) {
            dfs(s, idx + 1, left - 1, right, open, curr);
        }

        if (s[idx] == ')' && right > 0) {
            dfs(s, idx + 1, left, right - 1, open, curr);
        }

       
        if (s[idx] == '(') {
            curr.push_back('(');

            dfs(s, idx + 1, left, right, open + 1, curr);

            curr.pop_back();
        }
        else if (s[idx] == ')') {
            if (open > 0) {
                curr.push_back(')');

                dfs(s, idx + 1, left, right, open - 1, curr);

                curr.pop_back();
            }
        }
        else {
            curr.push_back(s[idx]);

            dfs(s, idx + 1, left, right, open, curr);

            curr.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int left = 0;
        int right = 0;

       
        for (char c : s) {
            if (c == '(') {
                left++;
            }
            else if (c == ')') {
                if (left > 0)
                    left--;
                else
                    right++;
            }
        }

        string curr;

        dfs(s, 0, left, right, 0, curr);

        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};