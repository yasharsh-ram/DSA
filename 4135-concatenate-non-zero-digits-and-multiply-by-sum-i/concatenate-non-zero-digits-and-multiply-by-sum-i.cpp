class Solution {
public:
    long long sumAndMultiply(int n) {
        int ans = 0;
        int place = 1;
        long sum = 0;
        while (n > 0) {
            int digit = n % 10;
            if (digit != 0) {
                ans = digit * place + ans;
                place *= 10;
                sum += digit;
            }
            n /= 10;
        }
        return 1ll * sum * ans;
    }
};