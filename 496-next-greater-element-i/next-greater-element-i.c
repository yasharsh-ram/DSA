/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//  brute force
// int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size,
// int* returnSize) {
//     int* ans=(int*)malloc(nums1Size*sizeof(int));
//     *returnSize = nums1Size;
//     for (int i=0;i<nums1Size;i++){
//         ans[i]=-1;
//         for(int j=0;j<nums2Size;j++){
//             if(nums1[i]==nums2[j]){
//                 for(int k=j+1;k<nums2Size;k++){
//                     if(nums2[k]>nums1[i]){
//                         ans[i]=nums2[k];
//                         break;
//                     }
//                 }
//                 break;
//             }
//         }
//     }
//     return ans;
// }
// Monotonic stack
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size,
                        int* returnSize) {
    int* stack = (int*)malloc(nums2Size * sizeof(int));
    int top = -1;
    int map[10001];
    for (int i = 0; i < 10001; i++) {
        map[i] = -1;
    }
    for (int i = 0; i < nums2Size; i++) {
        int curr = nums2[i];
        while (top != -1 && curr > stack[top]) {
            map[stack[top]] = curr;
            top--;
        }
        stack[++top] = curr;
    }
    while (top != -1) {
        top--;
    }
    int* ans = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;
    for (int i = 0; i < nums1Size; i++) {
        ans[i] = map[nums1[i]];
    }
    return ans;
}
