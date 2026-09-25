class Solution {
    set<string>solve(string& expression, int& curr){
        set<string> parts;
        set<string> ans;
        parts={""};
        while(curr<expression.size()){
            set<string> next;
            if(islower(expression[curr])){
            for(auto p : parts){
                next.insert(p + expression[curr]);
            }
            parts=next;
            curr++;
            
            }else if(expression[curr]=='{'){
                curr++;
                set<string> next=solve(expression,curr);
                set<string>temp;
                for(auto p:parts){
                for(auto s:next){
                    temp.insert(p+s);
                }
                }
                parts=temp;
            }else if(expression[curr]==','){
                ans.insert(parts.begin(),parts.end());
                parts.clear();
                parts.insert("");
                curr++;
            }else if(expression[curr]=='}'){
                ans.insert(parts.begin(),parts.end());
                curr++;
                return ans;
            }
        }
            ans.insert(parts.begin(),parts.end());
            return ans;
        
    }
    
public:
    vector<string> braceExpansionII(string expression) {
        int curr=0;
        set<string>result=solve(expression,curr);
        return vector<string>(result.begin(),result.end());
    }
};