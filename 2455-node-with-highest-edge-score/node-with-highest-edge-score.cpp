class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n=edges.size();
        vector<long long>score(n);
        for(int i=0;i<n;i++){
            score[edges[i]]+=i;
        }
        long long max=INT_MIN;
        int idx=0;
        for(int i=0;i<n;i++){
            if(score[i]>max){
                max=score[i];
                idx=i;
            }
        }
        return idx;
    }
};