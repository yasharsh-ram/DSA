#define MAXN 100005
#define MAXE 200005

int head[MAXN];
int to[MAXE];
int wt[MAXE];
int next[MAXE];
int idx;
int ans;
void addedje(int u,int v,int w){
    to[idx]=v;
    wt[idx]=w;
    next[idx]=head[u];
    head[u]=idx;
    idx++;
}
int visited[MAXN]={0};
void dfs(int node){
    visited[node]=1;
    for(int i=head[node];i!=-1;i=next[i]){
        if(wt[i]<ans){
            ans=wt[i];
        }
        int neighbour=to[i];
        if(!visited[neighbour]){
            dfs(neighbour);
        }
    }
}


int minScore(int n, int** roads, int roadsSize, int* roadsColSize) {
    idx=0;
    ans=INT_MAX;
    for(int i=1;i<=n;i++){
    head[i]=-1;
    visited[i]=0;
    }

for(int i=0;i<roadsSize;i++){
        int u=roads[i][0];
        int v=roads[i][1];
        int w=roads[i][2];
        addedje(u,v,w);
        addedje(v,u,w);
    }
    dfs(1);
    return ans;
    
}