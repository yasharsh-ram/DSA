class Solution {
    int calcdate(string day,vector<int>&prefixsum){
        int month=stoi(day.substr(0,2));
        int date=stoi(day.substr(3));
        return prefixsum[month-1]+date;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>dom={31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int>prefixsum={0};
        for(int x:dom){
            prefixsum.push_back(prefixsum.back()+x);
        }
        int alice=calcdate(arriveAlice,prefixsum);
        int alicelv=calcdate(leaveAlice,prefixsum);
        int bob=calcdate(arriveBob,prefixsum);
        int boblv=calcdate(leaveBob,prefixsum);

        return max(0,min(alicelv,boblv)-max(alice,bob)+1);
    }
};