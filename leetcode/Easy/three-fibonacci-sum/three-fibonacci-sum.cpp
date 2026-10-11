class Solution {
public:
    bool threeFibonacciSum(int n) {
        int a=0,b=1,c=1;
        while(true){
        int sum=a+b+c;
        if(sum==n)return true;
        if(sum>n)return false;
        int next=b+c;
        a=b;
        b=c;
        c=next;
    }
        return false;
    }
};