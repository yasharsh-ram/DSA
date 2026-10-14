class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum<0||sum>9*num)return "";
        int r=sum/9;
        int n=sum%9;
        string ans;
        // ans.reserve(num);
        ans.append(r,'9');
        if(n>0){
            ans+=to_string(n);
        }
        while(ans.size()<num){
            ans+='0';
        }
        return ans;
    }
};