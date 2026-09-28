class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int brace=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                brace++;
            }else if(s[i]==')'){
                brace--;
            }
            ans=max(ans,brace);
        }
        return ans;
    }
};