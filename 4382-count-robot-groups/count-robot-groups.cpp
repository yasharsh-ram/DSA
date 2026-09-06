class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n=position.size();
        int grp=1;
        int grpspd=speed[n-1];
        for(int i=n-2;i>=0;i--){
            if(position[i+1]-position[i]<=distance||speed[i]>grpspd){
                continue;
            }
            grp++;
            grpspd=speed[i];
        }
        return grp;
    }
};