/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     vector<int> nodesBetweenCriticalPoints(ListNode* head) {
//         vector<int> arr;
//         ListNode* temp = head;
//         while (temp != NULL) {
//             arr.push_back(temp->val);
//             temp = temp->next;
//         }
//         vector<int> crit;
//         int ans = 0;
//         for (int i = 1; i < arr.size()-1; i++) {
//             if ((arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) ||
//                 (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])) {
//                 crit.push_back(i);
//             }
//         }
//         if (crit.size() < 2)
//             return {-1, -1};
//         int mindis = INT_MAX;
//         for (int i = 1; i < crit.size(); i++) {
//             mindis = min(mindis, crit[i] - crit[i - 1]);
//         }
//         int maxdis = crit.back() - crit.front();
//         return {mindis, maxdis};
//     }
// };

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* next=curr->next;
        int index=1;
        int firstct=-1;
        int prevct=-1;
        int mindis=INT_MAX;
        while(curr->next!=NULL){
            if((curr->val<prev->val&&curr->val<next->val)||(curr->val>prev->val&&curr->val>next->val)){
                if(firstct==-1){
                    firstct=index;
                }else{
                    int dis=index-prevct;
                    mindis=min(mindis,dis);
                }
                prevct=index;
            }
            prev = curr;
            curr = curr->next;
            next = curr->next;
            index++;
        }
        if(firstct==-1||firstct==prevct)return{-1,-1};
        int maxdis=prevct-firstct;
        return{mindis,maxdis};
    }
};