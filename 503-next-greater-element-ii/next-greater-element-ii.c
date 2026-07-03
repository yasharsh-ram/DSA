/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* ans = (int*)malloc(numsSize * sizeof(int));
    for(int i=0;i<numsSize;i++){
        ans[i]=-1;
    }
    int* stack = (int*)malloc(numsSize * sizeof(int));
    int top = -1;
    for (int i = 0; i < 2*numsSize; i++){
        int curr=(i%numsSize);
        while(top!=-1&& nums[curr]>nums[stack[top]]){
            int idx=stack[top];
            top--;
            ans[idx]=nums[curr];
        }
        if(i<numsSize){
            stack[++top]=curr;
        }
    }
    return ans;
}

    
