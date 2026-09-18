class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n=s.size();
        vector<int>frst(26,-1);
        vector<int>last(26,-1);
        for(int i=0;i<n;i++){
            int x=s[i]-'a';
            if(frst[x]==-1){
                frst[x]=i;
            }
            last[x]=i;
        }
        vector<pair<int,int>>v;
        for(int c=0;c<26;c++){
            if (frst[c]==-1)continue;
            int left=frst[c];
            int right=last[c];
            bool ok=true;
            for(int i=left;i<=right;i++){
                int x=s[i]-'a';
                if(frst[x]<left){
                ok=false;
                break;
                }
                right=max(right,last[x]);
            }
            if(ok){
                v.push_back({right,left});
            }
        }
        sort(v.begin(),v.end());
        vector<string>ans;
        int prevgt=-1;
        for(auto p:v){
            int right=p.first;
            int left=p.second;
            if(left>prevgt){
                ans.push_back(s.substr(left,right-left+1));
                prevgt=right;
            }
        }
        return ans;
    }
};