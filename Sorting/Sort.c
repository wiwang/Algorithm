#include <stdio.h>
#include "Sort.h"


int GetMethod(char *method)
{
    if(strcmp("insertion", method) == 0) return InsertionSortMethod;
    if(strcmp("shell", method) == 0) return ShellSortMethod;
    if(strcmp("quick", method) == 0) return QuickSortMethod;
    if(strcmp("bublle", method) == 0) return BubbleSortMethod;
    if(strcmp("selection", method) == 0) return SelectionSortMethod;
    if(strcmp("merge", method) == 0) return MergeSortMethod;
    if(strcmp("heap", method) == 0) return HeapSortMethod;
    
    return InvalidMethod;
}

/*straight insertion sort*/

void InsertSort(int array[], int len)
{
    int i, j, n;
    int tmp;

    for(i=1; i<len; i++)
    {
        tmp = array[i];

        n = i;
        for(j=i-1; j>=0&&tmp<array[j]; j--)
        {
            array[j+1] = array[j];
            n=j;
        }
        
        array[n] = tmp;
    }

    return;
}


/*shell sort as diminishing increment sort*/
void ShellInsert(int array[], int len, int dk)
{
    int i, j, n;
    int tmp;
    
    for(i=dk; i<len; i++)
    {
        tmp = array[i];

        n = i;
        for(j=i-dk; j>=0&&tmp<array[j]; j-=dk)
        {
            array[j+dk] = array[j];
            n = j;
        }
        
        array[n] = tmp;
    }

    return;
}

void ShellSort(int array[], int len, int dlta[], int t)
{
    int i;
    for(i=0; i<t; i++)
    {
        ShellInsert(array, len, dlta[i]);
    }

    return;
}

void BubbleSort(int array[], int len)
{
    int i, j;
    int need = 1;
    int tmp;

    for(i=len-1; i>0 && need; i--)
    {
        need = 0;
        for(j=0; j<i; j++)
        {
            if(array[j] > array[j+1])
            {
                tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                need = 1;
            }
        }
    }
    
    return;
}

/* to find the position of pivot which divides array into two parts*/
int Partition(int array[], int low, int high)
{
    printf("partition from %d to %d\n", low, high);

    int pivot = array[low];

    while(low < high)
    {
        while(low<high && pivot<=array[high]) high--; 
        array[low] = array[high];

        while(low<high && array[low]<=pivot) low++;
        array[high] = array[low];
    }
    
    printf("pivot is %d, position is %d\n", pivot, low);
    
    array[low] = pivot;
    
    return low;
}

void QuickSort(int array[], int low, int high)
{
    int pivot;
    
    if(low < high)
    {
        pivot = Partition(array, low, high);

        QuickSort(array, low, pivot-1);
        QuickSort(array, pivot+1, high);
    }

    return;
}

int main(int argc, char* argv[])
{
    int i;
    int len;
    char* method = NULL;
    int array[] = {5,10,34,12,4,2,99,1,1024};
    int dlta[] = {5,3,1};

    method = argv[1];
    len = sizeof(array)/sizeof(int);

    printf("Algorithm is %s.\n", method);

    switch(GetMethod(method))

    {
        case InsertionSortMethod:
             InsertSort(array, len); 
             break;

        case ShellSortMethod:
             ShellSort(array, len, dlta, 3);
             break;

        case BubbleSortMethod:
             BubbleSort(array, len);
             break;

        case QuickSortMethod:
             QuickSort(array, 0, len-1);
             break;

        default:
             printf("can't support algorithm %s.\n", method);
    }


    printf("Algorithm %s result is :", method);
    for(i=0; i<len; i++)
        printf("%d,", array[i]);

    printf("\n");
    return 0;
}










