// class Solution {
// public:
//     vector<string> createGrid(int m, int n) {
//         vector<string>grid(m,string(n,'#'));
//         for(int i=0;i<n;i++){
//             grid[0][i]='.';
//         }
//         for(int j=1;j<m;j++){
//             grid[j][n-1]='.';
//         }
//         return grid;
//     }
// };

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid;
        grid.push_back(string(n,'.'));
        string row=string(n-1,'#')+'.';
        for(int i=1;i<m;i++){
            grid.push_back(row);
        }
        return grid;
    }
};