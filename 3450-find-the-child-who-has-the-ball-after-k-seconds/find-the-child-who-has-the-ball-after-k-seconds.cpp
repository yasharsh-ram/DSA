class Solution {
public:
    int numberOfChild(int n, int k) {
        int ans=k/(n-1);
        int count=k%(n-1);
        if(ans%2==0){
            return count;
        }
        return n-1-count;
        
    }
};