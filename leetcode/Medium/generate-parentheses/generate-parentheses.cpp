class Solution {
    void dfs(string& brak,int open,int n,vector<string>& ans){
        if(n==0&&open==0){
            ans.push_back(brak);
            return;
        }
        if(open){
            brak+=')';
            dfs(brak,open-1,n,ans);
            brak.pop_back();
        }
        if(n){
            brak+='(';
            dfs(brak,open+1,n-1,ans);
            brak.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string brak="";
        int open=0;
        dfs(brak,open,n,ans);
        return ans;
    }
};