
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
