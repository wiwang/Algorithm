/*
Add Binary

Given two binary strings, return their sum(also a binary string).

For example

a="11"
b="1"

Return "100"

Difficulty: Easy
*/


#include <stdio.h>
#include <string.h>

int binStringToNum(char *string)
{
    int num = 0;

    if (string == NULL) return -1;

    while(*string !='\0')
    {
        num*=2;
        if(*string == '1') num+=1;
        string++;
    }

    return num;
}

void numToBinString(int num, char string[])
{
     while(num != 0)
     {
         *string++ = (num%2==1) ? '1':'0';
         num /= 2;
     }
     *string = '\0';
     
     return;
}

void reverseString(char* str)
{
     char tmp;
     char *start, *end;
     
     if(str == NULL)return;

     for(start=str, end=str+strlen(str)-1; start<end; start++, end--)
     {
         tmp = *start;
         *start = *end;
         *end = tmp;
     }
     
     return;
}

int main(int argc, char *argv[])
{
    int sum;
    char strBuffer[20];
    if (argc == 3)
    {
        sum = binStringToNum(argv[1]) + binStringToNum(argv[2]);
        numToBinString(sum, strBuffer);
        reverseString(strBuffer);
        printf("The string of %d is %s\n", sum, strBuffer);
    }    

    return 0;
}
