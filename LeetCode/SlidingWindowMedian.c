double getMedian(int* nums, int numsSize)
{
    int start = 0;
    int end = numsSize-1;
    while(start <= end)
    {
        start++;
        end++;
    }
    
    return (nums[start]+nums[end])/2;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* medianSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int start = 0;
    *returnSize = (numsSize-k+1);
    double *medianArray = (double *)malloc(sizeof(double)*(*returnSize));
    for(start=0; start<=*returnSize; start++) {
        medianArray[start] = getMedian(nums+start, k);
    }
    
    return medianArray;
}