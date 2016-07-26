#include <stdio.h>


int binarySearch(int array[], int start, int end, int key)
{
    if (start > end)
       return -1;    

    int mid = (start+end)/2;

    if (key == array[mid])
    {
       return mid;
    }
    else if(key < array[mid])
    {
       return binarySearch(array, start, mid-1, key);
    }
    else
    {
       return binarySearch(array, mid+1, end, key);
    }    
}


int main(int argc, void *argv[])
{
    int array[] = {-10,-9, 4, 5, 8, 100, 2300, 5600, 5601, 8900};
    int key = 100;
    printf("key %d is in position %d of array.\n", key, binarySearch(array, 0, sizeof(array)/sizeof(int)-1, key));
    return 0;
}
