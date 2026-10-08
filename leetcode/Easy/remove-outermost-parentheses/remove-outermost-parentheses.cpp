class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth=0;
        string ans;
        for(int i=0;i<s.length();i++){
            char c=s[i];
        if(s[i]=='('){
                depth++;
                if(depth>1)ans+=c;
            
        }else{
            depth--;
            if(depth>0)ans+=c;
        }
        }
        return ans;
    }
};