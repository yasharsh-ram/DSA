int cmp(const void* a, const void* b) { return (*(int*)a - *(int*)b); }

int maximumElementAfterDecrementingAndRearranging(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    int ans = 1;
    for (int i = 1; i < arrSize; i++) {
        if (arr[i] >= ans + 1) {
            ans += 1;
        }
    }
    return ans;
}