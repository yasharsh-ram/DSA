class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
       const int LOG=20;
       vector<pair<int,int>>arr;
       for(int i=0;i<n;i++){
        arr.push_back({nums[i],i});
       }
       sort(arr.begin(),arr.end());
       vector<int>pos(n);
       for(int i=0;i<n;i++){
        pos[arr[i].second]=i;
       }
        vector<int>comp(n);
        comp[0]=0;
        for(int i=1;i<n;i++){
            if(arr[i].first-arr[i-1].first<=maxDiff){
                comp[i]=comp[i-1];
            }else{
                comp[i]=comp[i-1]+1;
            }
        }
        vector<int>next(n);
        int j=0;
        for(int i=0;i<n;i++){
            while(j<n && arr[j].first-arr[i].first<=maxDiff){
                j++;
            }
            next[i]=j-1;
        }
        vector<vector<int>>jump(n,vector<int>(LOG));
        for(int i=0;i<n;i++){
            jump[i][0]=next[i];
        }
            for(int k=1;k<LOG;k++){
                for(int i=0;i<n;i++){
                jump[i][k]=jump[jump[i][k-1]][k-1];
            }
        }
        
        vector<int>ans;
        for(auto &q:queries){
            int u=pos[q[0]];
            int v=pos[q[1]];
            if(u>v)swap(u,v);
            if(u==v){
                ans.push_back(0);
                continue;
            }
            if(comp[u]!=comp[v]){
                ans.push_back(-1);
                continue;
            }else{
                int curr=u;
                int cnt=0;
                for(int k=LOG-1;k>=0;k--){
                    if(jump[curr][k]<v){
                        curr=jump[curr][k];
                        cnt+=(1<<k);
                    }
                    
                }
                cnt++;
                ans.push_back(cnt);
            }
        }
        
        return ans;
    }
};