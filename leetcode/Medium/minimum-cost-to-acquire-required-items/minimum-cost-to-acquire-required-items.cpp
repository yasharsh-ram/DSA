class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long res=0;
        if(1LL*cost1+cost2<=costBoth){
            return 1LL*cost1*need1+1LL*cost2*need2;
            }
        if(need1<=need2){
            res+=1LL*costBoth*need1;
            need2-=need1;
            return res+1LL*need2*min(costBoth,cost2);
        }else{
            res+=1LL*costBoth*need2;
            need1-=need2;
            return res+1LL*need1*min(costBoth,cost1);
        }
    }
};