#include <stdio.h>

int Myatoi(const char *str)
{
    int sign = 1;
    int num = 0;

    if(*str == '-')
    {
        sign = -1;
        str++;
    }

    while(*str != '\0')
    {
        num = num*10 + (*str-'0');
        str++;    
    }

    return num*sign;
}

double Myatof(const char *str)
{
    double base = 10;
    double num = 0;
    int sign = 1;

    if(*str == '-')
    {
        sign = -1;
        str++;
    }

    while(*str != '\0')
    {
        if(*str != '.')
        {
            num = num*10 + (*str-'0');
            str++;
        }
        else
        {
            str++;
            break;
        }
    }

    while(*str != '\0')
    {            
        num = num + (*str-'0')/base;
        base *= 10;
        str++;
    }

    return num*sign;
}

int main(int argc, char *argv[])
{
    printf("int is %d, float is %f\n", Myatoi("123"), Myatof("123.123"));
    return 0;
}