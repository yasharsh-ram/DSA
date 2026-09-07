class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        for(auto x:freq){
            q.push({x.second,x.first});
            if(q.size()>k)q.pop();
        }
        vector<int>ans;
        while(!q.empty()){
            ans.emplace_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};