#include <stdio.h>


unsigned int recursive(unsigned int n)
{
    if(n==0) return 1;
    if(n==1) return 1;

    return (recursive(n-1)+recursive(n-2));

}

unsigned int loop(unsigned int n)
{
    int i;
    unsigned int before, tmp;
    unsigned int ret;

    for(i=0; i<n; i++)
    {
        if(i==0){ret=1; before=1; continue;}
        tmp = ret;
        ret+=before;
        before = tmp;
    }

    return ret;
}


int main(int argc, char *argv[])
{
    printf("for recursive, Fibonacci result of 20 is:\n");

    printf("%d\n", recursive(20));

    printf("for loop, Fibonacci result of 20 is:\n");

    printf("%d\n", loop(20));

    return 0;
}
