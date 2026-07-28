class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s)
            freq[c - 'a']++;
        string ans = "";
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 1) {
                ans += char('a' + i);
                freq[i] -= 2;
            }
        }
        string temp = ans;
        reverse(temp.begin(), temp.end());

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 1) {
                ans += char('a' + i);
                break;
            }
        }
        return ans + temp;
    }
};