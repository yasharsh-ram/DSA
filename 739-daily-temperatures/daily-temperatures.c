/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// int* dailyTemperatures(int* temperatures, int temperaturesSize,int*
// returnSize) {
// Bruteforce 
//     *returnSize = temperaturesSize;
//     int* ans = (int*)malloc(temperaturesSize * sizeof(int));
//     for (int i = 0; i < temperaturesSize; i++) {
//         ans[i] = 0;
//         for (int j = i + 1; j < temperaturesSize; j++) {
//             if (temperatures[j] > temperatures[i]) {
//                 ans[i] = j - i;
//                 break;
//             }
//         }
//     }
//     return ans;
// }
// Monotonic stack approach
int* dailyTemperatures(int* temperatures, int temperaturesSize,
                       int* returnSize) {
    *returnSize = temperaturesSize;
    int* ans = (int*)malloc(temperaturesSize * sizeof(int));
    int* stack = (int*)malloc(temperaturesSize * sizeof(int));
    int top = -1;
    for (int i = 0; i < temperaturesSize; i++) {
        ans[i] = 0;
        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top];
            top--;
            ans[idx] = i - idx;
        }
        stack[++top] = i;
    }
    return ans;
}
