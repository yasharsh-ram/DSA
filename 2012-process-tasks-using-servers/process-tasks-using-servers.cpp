class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> available;priority_queue<tuple<long long,int,int>,vector<tuple<long long,int,int>>,
    greater<tuple<long long,int,int>>> busy;
        vector<int>ans(tasks.size());
        for(int i=0;i<servers.size();i++){
            available.push({servers[i],i});
        }
        long long currtm=0;
        for(int j=0;j<tasks.size();j++){
            currtm=max(currtm,(long long)j); 
            while(!busy.empty()&&get<0>(busy.top())<=currtm){
                auto[freetime,weight,index]=busy.top();
                busy.pop();
                available.push({weight,index});
            }
            if(available.empty()){
                currtm=get<0>(busy.top());
                while(!busy.empty()&&get<0>(busy.top())<=currtm){
                auto[freetime,weight,index]=busy.top();
                busy.pop();
                available.push({weight,index});
            }
            }
        auto[weight,index]=available.top();
        available.pop();
        ans[j]=index;
        busy.push({currtm+tasks[j],weight,index});
        }
        return ans;
    }
};