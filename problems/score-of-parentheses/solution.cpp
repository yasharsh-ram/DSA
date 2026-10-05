class Solution {
public:
    int scoreOfParentheses(string s) {
        int low=0;
        int score=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                low++;
            }else{
                low--;
                if(i>0&&s[i-1]=='('){
                    score+=1<<low;
                }
                
            }
        }
        return score;
    }
};