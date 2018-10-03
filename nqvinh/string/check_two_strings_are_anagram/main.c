#include <string.h>
#include <stdio.h>
#include <ctype.h>

int check2StringAreAnagram(const char *str1,const char *str2);

int main(int argc, char const *argv[])
{
    char *string1 = "abcdefgh";
    char *string2 = "hgfedxba";

    check2StringAreAnagram(string1, string2) ? printf("YES\n") : printf("NO\n");
    return 0;
}

int check2StringAreAnagram(const char *str1, const char *str2)
{
    unsigned int length1 = strlen(str1);
    unsigned int length2 = strlen(str2);

    if (length1 != length2)
    {
        return 0;
    }

    for (int i = 0 ; i < length1; i++)
    {
        if (*(str1 + i) != *(str2 + length2 - 1 - i))
        {
            return 0;
        }
    }
    return 1;
}
