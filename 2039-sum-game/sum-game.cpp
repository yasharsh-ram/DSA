class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int half = n / 2;
        int ql = 0, qr = 0, diff = 0;
        for (int i = 0; i < n; i++) {
            if (i < half) {
                if (num[i] == '?')
                    ql++;
                else
                    diff += num[i] - '0';
            } else {
                if (num[i] == '?')
                    qr++;
                else
                    diff -= num[i] - '0';
            }
        }
            if ((ql + qr) & 1)
                return true;
        
        return diff != 9 * (qr - ql)/2;
    }
};