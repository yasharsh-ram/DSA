class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
//         // int depth = 0;
//         // vector<int> ans;
//         // for (int i = 0; i < seq.length(); i++) {
//         //     if (seq[i] == '(') {
//         //         depth++;
//         //         if (depth % 2 == 1) {
//         //             ans.push_back(0);
//         //         } else {
//         //             ans.push_back(1);
//         //         }
//         //     } else {
//         //         if (depth % 2 == 1) {
//         //             ans.push_back(0);
//         //         } else {
//         //             ans.push_back(1);
//         //         }
//         //         depth--;
//         //     }
//         // }
//         // return ans;
//     }
// };

int depth = 0;
vector<int> ans;

for(char ch : seq) {
    if(ch == '(') {
        depth++;
        ans.push_back(depth % 2);
    } 
    else {
        ans.push_back(depth % 2);
        depth--;
    }
}

return ans;
    }
};