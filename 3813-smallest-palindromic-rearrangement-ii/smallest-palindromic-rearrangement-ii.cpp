class Solution {
public:
    // vector<long long> fact;
    // long long countways(vector<int>& freq) {
    //     int total = 0;
    //     for (int x : freq)
    //         total += x;
    //     long long ways = fact[total];
    //     for (int x : freq)
    //         ways /= fact[x];
    //     return ways;
    // }
    // Calculate:
        // total! / (freq[0]! * freq[1]! * ...)
        //
        // But cap the answer at k.
    long long countways(vector<int>& freq, long long k) {
        long long ways = 1;
        int total = 0;

        for (int x : freq)
            total += x;
        for (int x : freq) {
            if (x == 0)
                continue;

            for (int i = 1; i <= x; i++) {
                ways = ways * (total - x + i) / i;

                if (ways >= k)
                    return k;
            }

            total -= x;
        }

        return ways;
    }
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        vector<int> original = freq;

        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }
        int len = 0;
        for (int x : freq)
            len += x;

        // fact.resize(len + 1);
        // fact[0] = 1;

        // for (int i = 1; i <= len; i++)
        //     fact[i] = fact[i - 1] * i;
        if (countways(freq,k) < k)
            return "";
        
        string firsthalf = "";
        for (int pos = 0; pos < len; pos++) {
            for (int c = 0; c < 26; c++) {
                if (freq[c] == 0)
                    continue;
                freq[c]--;
                long long ways = countways(freq,k);
                if (ways >= k) {
                    firsthalf += char('a' + c);
                    break;
                }
                k -= ways;
                freq[c]++;
            }
        }
        string second = firsthalf;
        reverse(second.begin(), second.end());
        string mid = "";
        for (int i = 0; i < 26; i++) {
            if ((original[i] & 1)) {
                mid += char('a' + i);
                break;
            }
        }
        return firsthalf + mid + second;
    }
};