class Solution {
public:
    int smallestNumber(int n, int t) {
        int num=n;
        while(true){
            int pro=1;
            n=num;
            while(n){
                pro*=n%10;
                n/=10;
            }
            if(pro%t==0)break;
            else
            ++num;
        }
        return num;
    }
};