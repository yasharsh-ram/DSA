class Solution {
public:
    bool canAliceWin(int n) {
        int rem=10;
        bool alice=false;
        while(n>=rem){
            n-=rem;
            rem--;
            alice=!alice;
        }
        return alice;
    }
};