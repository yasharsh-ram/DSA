class Solution {
    // bool isprime(int i){
    //     if(i<2)return false;
    //     for(int j=2;j*j<=i;j++){
    //         if(i%j==0)return false;
    //     }
    //     return true;
    // }
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> prime(n + 1, true);

        if (n >= 0) prime[0] = false;
        if (n >= 1) prime[1] = false;

        for (int i = 2; 1LL * i * i <= n; i++) {
            if (prime[i]) {
                for (long long j = 1LL * i * i; j <= n; j += i) {
                    prime[j] = false;
                }
            }
        }
        vector<int>ans;
        int sum=0;
        for(int i=2;i<=n;i++){
            if(prime[i]&&i<=s-sum){
                ans.push_back(i);
                sum+=i;
            }
            if(sum==s)break;
            
        }
        return ans;
    }
};