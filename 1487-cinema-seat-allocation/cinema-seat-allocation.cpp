class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int ans=n*2;
        unordered_map<int,tuple<bool,bool,bool>>reserved;
        for(int i=0;i<reservedSeats.size();i++){
            int row=reservedSeats[i][0];
            int seat=reservedSeats[i][1];
            if(seat>=2&&seat<=5)get<0>(reserved[row])=true;
            if(seat>=4&&seat<=7)get<1>(reserved[row])=true;
            if(seat>=6&&seat<=9)get<2>(reserved[row])=true;
        }
        for(auto &[key,val]:reserved){
            auto&[l,m,r]=val;
            if(l==1&&m==1&&r==1){
                ans-=2;
            }else if(l||m||r){
                ans-=1;
            }
        }
return ans;
    }
};