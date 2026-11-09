class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int>available;
        for(int i=0;i<k;i++){
            available.insert(i);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>busy;
        vector<int>counts(k,0);
        for(int i=0;i<arrival.size();i++){
            int arrtime=arrival[i],loadtime=load[i];
            while(!busy.empty()&&busy.top().first<=arrtime){
                available.insert(busy.top().second);
                busy.pop();
            }
            if(available.empty())continue;
            auto it=available.lower_bound(i%k);
            if(it==available.end())it=available.begin();
            int serverid=*it;
            available.erase(it);
            counts[serverid]++;
            busy.push({arrtime+loadtime,serverid});
        }
        int maxs=*max_element(counts.begin(),counts.end());
        vector<int>res;
        for(int i=0;i<k;i++){
            if(counts[i]==maxs)res.push_back(i);
        }
        return res;
    }
};