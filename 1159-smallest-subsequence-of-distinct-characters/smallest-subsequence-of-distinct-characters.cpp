class Solution {
public:
    string smallestSubsequence(string s) {
        vector<char>st;
        vector<int>freq(26);
        vector<bool>visited(26,false);
        for(int i=0;i<s.length();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<s.length();i++){
        char curr=s[i];
        freq[curr-'a']--;
        if(visited[curr-'a'])continue;
        while(!st.empty()&&st.back()>curr&&freq[st.back()-'a']>0){
            visited[st.back()-'a']=false;
            st.pop_back();
        }
        st.push_back(curr);
        visited[curr-'a']=true;
        }
        return string(st.begin(),st.end());
    }
};