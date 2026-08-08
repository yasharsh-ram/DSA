class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int N=word1.length();
        int M=word2.length();
        vector<int>last(M,-1);
        for(int i=N-1,j=M-1;i>=0&&j>=0;--i){
            if(word1[i]==word2[j]){
                last[j]=i;
                --j;
            }
        }
        bool canchange=true;
        vector<int>ans(M);
        int j=0;
        for(int i=0;i<N&&j<M;++i){
            if(word1[i]==word2[j]){
                ans[j++]=i;
            }else if(canchange&&(j==M-1||i<last[j+1])){
                ans[j++]=i;
                canchange=false;
            }
            if(j==M)return ans;
        }
        return vector<int>{};
        
    }
};