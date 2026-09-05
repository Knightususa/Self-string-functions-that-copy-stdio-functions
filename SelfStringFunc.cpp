#include <stdio.h>
#include <cstdlib>
#include <stdbool.h>
#include <assert.h>

int   Selfstrlen (const char* str);
int   Selfputs   (const char* str);
int   Selfstrcmp (const char* lhs, const char* rhs);
int   SelfstrNcmp(const char* lhs, const char* rhs, int N);
bool   IsSubStr   (const char* str, const char* substr, int i);
char* Selfstrstr (const char* str, const char* substr); 
char* Selfstrdup (const char* str1);
char* Selfstrcpy (char* dest, const char* src);
char* Selfstrcat (char* dest, const char* src);
char* Selfgetline(char* line, FILE* input, const char end);
// -------------------
int main()
{
    char testlen[] = "<MUDRY DUB>";
    printf("\nstrlen(%s) = %i\n\n", testlen, Selfstrlen(testlen));

    char testputs[] = "<polozi eto>";
    Selfputs(testputs);


    const char abc[] = "1234abc";
    char abccopy[20] = {};
    Selfstrcpy(abccopy, abc);
    printf("\n\nabccopy of abc = <%s>\n", abccopy);

    char aboba[20] = "ABOBA";
    char bus[] = "BUS";
    Selfstrcat(aboba, bus);
    printf("\naboba + bus = <%s>\n", aboba);

    char stri1[] = "abcc";
    char stri2[] = "abcd";
    printf("\n\"%s\" and \"%s\" = %i\n", stri1, stri2, Selfstrcmp(stri1 , stri2));

    char stri3[] = "abcc";
    char stri4[] = "abcd";
    printf("\n\"%s\" and \"%s\" = %i\n", stri3, stri4, SelfstrNcmp(stri3 , stri4, 4));

    char stri5[] = "abcdefgh";
    char stri6[] = "cde";
    printf("\n\"%s\" in \"%s\" = %i\n", stri6, stri5, Selfstrstr(stri5, stri6));

    printf("\nInput smthng\n");
    char inputLine[] = {};
    char inputEnd = '\n';
    printf("Your input is <%s>\n", Selfgetline(inputLine, stdin, inputEnd));

    printf("Hell");
}
// -------------------
int Selfstrlen(const char* str)
{
    assert(str != NULL);
    int i = -1;
    while(str[++i] != '\0')
        ;
    return i;
}

int Selfputs(const char* str)
{
    assert(str != NULL);
    int  i = 0;
    char tempc = 0;

    while((tempc = str[i++]) != '\0')
    {
        putchar(tempc);
    }

    if(tempc == '\0')
    {
        return i;
    }
    return EOF;
}

char* Selfstrcpy (char* dest , const char* src)
{
    assert(dest != NULL);
    assert(src  != NULL);
    int  i = 0;
    char tempc = 0;
    while((tempc = src[i]) != '\0')
    {
        dest[i] = tempc;
        i++;
    }
    dest[++i] = '\0';
    return dest;
}

char* Selfstrcat (char* dest , const char* src)
{
    assert(dest != NULL);
    assert(src  != NULL);
    int i = 0;
    while(dest[i++] != '\0')
        ;
    int j = 0;
    i--;

    while(src[j] != '\0') 
    {
        dest[i++] = src[j++];
    }
    return dest;
}

int Selfstrcmp(const char* lhs, const char* rhs)
{
    assert(lhs != NULL);
    assert(rhs != NULL);
    int  i = 0;
    char l = 0, r = 0; 
    while(((l = lhs[i]) != '\0') && ((r = rhs[i]) != '\0'))
    {
        if(l < r)
        {
            return -1;
        }
        else if(l > r)
        {
            return 1;
        }
        i++;
    }
    r = rhs[i];
    return l - r;
}

int SelfstrNcmp(const char* lhs, const char* rhs, int N)
{
    assert(lhs != NULL);
    assert(rhs != NULL);
    int  i = 0;
    char l = 0, r = 0; 
    while(((l = lhs[i]) != '\0') && ((r = rhs[i]) != '\0') && i < N - 1)
    {
        if(l < r)
        {
            return -1;
        }
        else if(l > r)
        {
            return 1;
        }
        i++;
    }
    r = rhs[i];
    return l - r;
}

char* Selfstrstr (const char* str, const char* substr)
{
    assert(str    != NULL);
    assert(substr != NULL);
    char* firstc = NULL;
    int i = 0;
    bool isSubStr = 0;
    while(!isSubStr && i < Selfstrlen(str))
    {
        if(str[i] == substr[0]) 
        {
            isSubStr = IsSubStr(str, substr, i);
        }
        if(isSubStr)
        {
            firstc = (char*) str + i;
            return firstc;
        }
        i++;
    }
    return firstc;
}

bool IsSubStr(const char* str, const char* substr, int i)
{
    assert(str    != NULL);
    assert(substr != NULL);
    int j = 0;
    int lenSubstr = Selfstrlen(substr);
    int lenStr = Selfstrlen(str);
    while(j < lenSubstr && i < lenStr)
    {
        if(str[i] != substr[j]) 
        {
            return 0;
        }
        i++;
        j++;
    }
    return 1;
}

char* Selfgetline(char* line, FILE* input, const char end)
{
    assert(line != NULL);
    char tempc = getc(input);
    int i = 0;
    while(tempc != end)
    {
        line[i] = tempc;
        tempc = getc(input);
        i++;
    }
    line[i] = 0;
    return line;
}

char* Selfstrdup (const char* str1)
{
    assert(str1 != NULL);
    char* strcopy = (char*) calloc(Selfstrlen(str1), sizeof(strcopy[0]));
    int i = 0;
    while(str1[i] != '\0')
    {
        strcopy[i] = str1[i];
        i++;
    }
    return strcopy;
}