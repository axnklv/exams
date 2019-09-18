// Assignment name  : ft_strdup
// Expected files   : ft_strdup.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
//
// Reproduce the behavior of the function strdup (man strdup).
//
// Your function must be declared as follows:
//
// char    *ft_strdup(char *src);

int len(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (len);
}

char *ft_strdup(char *src)
{
    int i;
    int len;
    char *dst;

    i = 0;
    len = len(src);
    dst = (char *)malloc(sizeof (char) * (len + 1);
    if (!dst)
        return (NULL);
    while (dst[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}
