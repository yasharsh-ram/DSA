class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        unordered_map<char, int> freq(n);
        for (int i = 0; i < n; i++) {
            freq[s[i]]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto x : freq) {
            pq.push({x.second, x.first});
        }
        string ans = "";
        while (!pq.empty()) {
            int fre = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            for (int i = 0; i < fre; i++) {
                ans += ch;
            }
        }

            return ans;
        
    }
};