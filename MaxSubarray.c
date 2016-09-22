#include <stdio.h>

typedef struct
{
    int start;
    int end;
}ArrayTuple;

int FindMaxCrossingSubarray(int array[], int low, int mid, int high, ArrayTuple *subArray)
{
    int leftMax, rightMax;
    int sum, i;

    subArray->start = mid;

    for(i=mid, leftMax=array[i]; i>=low; i--)
    {
        sum += array[i];
        if(sum > leftMax)
        {
           subArray->start = i;
           leftMax = sum;
        }
    } 

    sum = 0;
    subArray->end = mid+1;    

    for(i=mid+1, rightMax=array[i]; i<=high; i++)
    {
        sum += array[i];
        if(sum > rightMax)
        {
            subArray->end = i;
            rightMax = sum;
        }
    }

    return (leftMax+rightMax);
}

int main(int argc, void *argv[])
{
    int sum;
    int len;

    int testArray[] = {-100,13,23,-30,70,1,0,-43};    
    
    ArrayTuple subArray;
    len = sizeof(testArray)/sizeof(int);
    sum = FindMaxCrossingSubarray(testArray, 0, len/2, len-1, &subArray);
    
    printf("subArray start from %d to %d with sum %d.\n", subArray.start, subArray.end, sum);
    return 0;
}


