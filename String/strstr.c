
char* strstr(const char* src, const char* dst)
{
    char* s = NULL;
    char* d = NULL;

    if(src==NULL || dst==NULL)
        return NULL;

    while(*src != '\0')
    {
        s = src;
        d = dst;
        while(*s==*d && *d!='\0')
        {
            s++;
            d++;
        }
  
        if(*d == '\0')
        {
            return src;
        }

        src++;
    }

    return NULL;
}



int removesubstr(char* src, const char* dst)
{
    int found = 0;
    char* s = NULL;
    char* d = NULL;

    if(src==NULL || dst==NULL)
        return NULL;

    while(*src != '\0')
    {
        s = src;
        d = dst;
        while(*s==*d && *d!='\0')
        {
            s++;
            d++;
        }

        if(*d == '\0')
        {
            found = 1;
            break;
        }

        src++;
    }

    if(found)
    {
        while((*s++=*dst++) != '\0');
    }
    
    return found;
}


/*
next[j] is the index for array[j] match array[n] or n-j when the match fail or 0 when j is 1
assuming the array[0] is the length of array[n]
*/

void getNextArray(int next[], char array[], int n)
{
    int i, j;

    next[0] = 1;

    
    for(i=1; i<n-1; i++)
    {
        for(j=1; j<=n-i; j++)
        {
            //match array[0--i] in array[j--(n-i)]
            if (strncpy(array, &array[j], i) == 0)
            break;          
        }
        next[i] = j;
    }

    return;
}


/*
O(m+n) for time complexity, the core theory is calculate the next[j] before we start string match
so we need to get next[j] ahead
the String is stored in array[], the array[0] is the length of String
*/


int KMP(const char src[], const char dst[])
{
    char i=j=1;

    while(i<=src[0] && j<=dst[0])
    {
        if(src[i]=dst[j])
        {
            i++;
            j++;
        }
        else
        {
            j=next[j];
        }
    }
    
    if(j > dst[0]) return i-T[0];
    else return 0;
}
