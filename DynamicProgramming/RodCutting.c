#include <stdio.h>
#include <limits.h>

#define MAX(a,b) (a>b ? a : b)

int rodCutting(int p[], int n)
{
    int i;
    int max = INT_MIN;
    
    if(n == 0) return 0;

    for(i=1; i<=n; i++)
    {
        max = MAX(max, p[i]+rodCutting(p, n-i));
    }

    return max;
}



int main(int argc, void *argv[])
{
    int p[] = {5,1,8,4,16,14,18,19,15,1,1,1,1,1,1,1,1,1,5,5,5,5,5,5,5,5,5,5,5,5,3,3,3,3,3,3,3,3,3,3,3,3,7,7,7,77,7,7,7,7,7,7,7};

    int maxRevenue;

    maxRevenue = rodCutting(p, 20);
    printf("the max revenue is %d\n", maxRevenue); 

    return 0;
}
