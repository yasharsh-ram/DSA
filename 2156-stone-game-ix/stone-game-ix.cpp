class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int zeroes=0;
        int ones=0;
        int twos=0;
        for(int i=0;i<stones.size();i++){
            int r=stones[i]%3;
            if(r==0)zeroes++;
            else if(r==1)ones++;
            else twos++;
        }
        if(zeroes%2==0){
            return ones>0 && twos>0;
        }else{ 
            return abs(ones-twos)>2;
        }
        
    }
};