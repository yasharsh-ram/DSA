class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        for(auto& k:knowledge){
            mpp[k[0]]=k[1];
        }
        string ans="";
        int start=-1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                start=i;
            }else if(s[i]==')'){
                string key=s.substr(start+1,i-start-1);
                if(mpp.count(key))ans+=mpp[key];
                else ans+="?";
                start=-1;
            }else if(start<0){
                ans+=s[i];
            }
        }
        return ans;
    }
};