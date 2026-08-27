class Solution {
    string getrem(const int* freq) {
        string res;
        for (int i = 0; i < 26; i++)
            res.append(freq[i], 'a' + i);
        return res;
    }

public:
    string lexGreaterPermutation(string s, string target) {
        int freq[26]{0};
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            freq[target[i] - 'a']--;
        }
        for (int i =s.length()-1; i >= 0; i--) {
            int b = target[i] - 'a';
            freq[b]++;
            if (*min_element(freq, freq + 26) < 0)
                continue;
            for (int j = b + 1; j < 26; j++) {
                if (freq[j]) {
                    freq[j]--;
                    target[i] = 'a' + j;
                    target.resize(i + 1);
                    return target + getrem(freq);
                }
            }
        }
        return "";
    }
};