class Solution {
public:
    int maxProduct(int n) {
        string s=to_string(n);
        sort(s.begin(),s.end());
        return (s[s.length()-1]-'0')*(s[s.length()-2]-'0');
    }
};