class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int INF=1e9;
        vector<int>start(n,INF);
        vector<int>end(n,INF);
        int left=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>target){
                sum-=arr[left];
                left++;
            }
            if(sum==target){
            start[left]=i-left+1;
            end[i] = i - left + 1;
            }
        }
        vector<int>suffix(n,INF);
        suffix[n-1]=start[n-1];
        for(int j=n-2;j>=0;j--){
            suffix[j]=min(start[j],suffix[j+1]);
        }
        vector<int>prefix(n,INF);
        prefix[0]=end[0];
        for(int i=1;i<n;i++){
            prefix[i]=min(end[i],prefix[i-1]);
        }
        int ans=INF;
        for(int i=1;i<n;i++){
            if(prefix[i-1]!=INF&&suffix[i]!=INF){
                ans=min(ans,prefix[i-1]+suffix[i]);
            }
        }
        return ans==INF?-1:ans;
    }
};