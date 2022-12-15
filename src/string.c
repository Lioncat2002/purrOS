int strlen(char *s)
{
    int i = 0;
    while (*s++)
        i++;
    return i;
}

int strcmp(const char *dst, char *src)
{

    int i = 0;
    while ((dst[i] == src[i]))
    {
        if (src[i++] == 0)
            return 0;
    }
    return 1;
}

int strcpy(char *dst, const char *src)
{
    int i = 0;
    while ((dst[i] = src[i++]))
        ;
    return i;
}

void strcat(void *dest, const void *src)
{
    memcpy((char *)((int)dest + (int)strlen((char *)dest)), (char *)src, strlen((char *)src));
}
