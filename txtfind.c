#include <stdio.h>
#include "txtfind.h"

#define FILE 100

int getLine(char s[])
{
    char c = 0;
    int ind = 0;
    scanf("%c", &c);
    while (c != '\n' && ind < LINE)
    {   
        s[ind] = c;
        ind++;
        scanf("%c", &c);
    }
    return ind;
}

int getWord(char w[])
{
    char c = 0;
    int ind = 0;
    scanf("%c", &c);
    while (c != '\n' && c != '\t' && c != ' ' && ind < WORD)
    {   
        *(w+ind) = c;
        ind++;
        scanf("%c", &c);
    }
    return ind;
}

static int STRLEN (char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}
//compare n chars of 2 string
static int STRNCMP(char *str1, char *str2, int n)
{
    for (int i=0; i<n; i++)
    {
        if(*(str1+i) != *(str2+i))
            return 0;
        if (*(str1+i) == '\0' && *(str2+i) != '\0')
            return 0;
        if (*(str2+i) == '\0' && *(str1+i) != '\0')
            return 0;
        if (*(str1+i) == '\0' && *(str2+i) == '\0')
            return 1;
    }
    return 1;
}

int subString(char *str1, char *str2)
{
    int n1 = STRLEN(str1);
    int n2 = STRLEN(str2);
    if(n2 > n1)
        return 0;
    if (n2 == 0 && n1 > 0)
        return 0;
    for(int i=0; i<=n1-n2; i++)
    {
        if(STRNCMP(str1+i, str2, n2))
            return 1;
    }
    return 0;
}

int similar (char *s, char *t, int n)
{
    int n1 = STRLEN(s);
    int n2 = STRLEN(t);
    if (n2 > n1)
        return 0;
    if (n == 0)
    {
        if (n1 != n2)
            return 0;
        return STRNCMP(s, t, n1);
    }
    int c = 0;
    while (*s != '\0' && *t != '\0')
    {
        if (*s == *t)
            t++;
        else
            c++;
        s++;
    }
    if (n == c + STRLEN(s))
        return 1;
    return 0;
}

void print_lines(char *str)
{
    char s[LINE] = {0};
    for (int i=0; i<MAXLINES; i++)
    {
        if (getLine(s) != 0)
        {
            if(subString(s, str) == 1)
            {
                printf("%s\n", s);
            }
        }
    }
}

void print_similar_words(char *str)
{
    char w[WORD] = {0};
    for(int i=0; i<MAXLINES*LINE; )
    {
        for(int i=0; i<WORD; i++)
            *(w+i) = 0;
        i += getWord(w) + 1;
        if(similar(w, str, 1) == 1 || similar(w, str, 0) == 1)
        {
            printf("%s\n", w);
        }
    }
}