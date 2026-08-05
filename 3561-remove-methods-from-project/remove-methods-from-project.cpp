constexpr int MAXN=100005;
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>edges(n);
        vector<int>indegree(n,0);
        bitset<MAXN>sus;
        for(const auto& inv:invocations){
            edges[inv[0]].push_back(inv[1]);
            indegree[inv[1]]++;
        }
        queue<int>q;
        q.push(k);
        sus.set(k);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:edges[u]){
                indegree[v]--;
                if(!sus.test(v)){
                    q.push(v);
                    sus.set(v);
                }
            }
        }
        bool canrm=true;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(sus.test(i)&&indegree[i]>0){
                canrm=false;
                break;
            }else if(!sus.test(i)){
                ans.push_back(i);
            }
        }
        if(!canrm){
            vector<int>allnodes(n);
            iota(allnodes.begin(),allnodes.end(),0);
            return allnodes;
        }
        
        return ans;
        
    }
};