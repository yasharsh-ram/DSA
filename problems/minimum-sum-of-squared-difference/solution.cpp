// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         priority_queue<int>pq;
//         for(int i=0;i<nums1.size();i++){
//             pq.push(abs(nums1[i]-nums2[i]));
//         }
//         int k=k1+k2;
//         while(k>0&&pq.top()>0){
//             int larg=pq.top();
//             pq.pop();
//             pq.push(larg-1);
//             k--;
//         }
//         long long ans=0;
//         while(!pq.empty()){
//             long long x=pq.top();
//             pq.pop();
//             ans+=x*x;
//         }
//         return ans;
//     }
// };

// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         vector<int>diff;
//         for(int i=0;i<nums1.size();i++){
//             diff.push_back(abs(nums1[i]-nums2[i]));
//         }
//         sort(diff.begin(),diff.end(),greater<int>());
//         long long k=(long long)k1+k2;
//     }
// };

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();
        int m=0;
        long long k=1LL*k1+k2;
        vector<int>bucket;
        for(int i=0;i<n;i++){
            m=max(m,abs(nums1[i]-nums2[i]));
        }
        bucket.assign(m+1,0);
        for(int i=0;i<n;i++){
            bucket[abs(nums1[i]-nums2[i])]++;
        }
        for(int i=m;i>0&&k>0;i--){
            long long take=min((long long)bucket[i],k);
            bucket[i]-=take;
            bucket[i-1]+=take;
            k-=take;
        }
        long long ans=0;
        for(int i=0;i<=m;i++){
            ans+=1LL*bucket[i]*i*i;
        }
        return ans;
    }
};