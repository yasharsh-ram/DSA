class Solution {
public:
    string reverseParentheses(string s) {
        string curr="";
        stack<string>stk;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                stk.push(curr);
                curr="";
            }else if(s[i]==')'){
                reverse(curr.begin(),curr.end());
                string prev=stk.top();
                stk.pop();
                curr=prev+curr;
            }else{
                curr+=s[i];
            }
        }
        return curr;
    }
};