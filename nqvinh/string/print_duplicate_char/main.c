#include <string.h>
#include <stdio.h>
#include <ctype.h>

void printDuplicateChar(const char *str);


int main(int argc, char const *argv[])
{
    char *string = "Cong hoa xa hoi chu nghia viet nam, doc lap tu do hanh phuc";

    printDuplicateChar(string);
    return 0;
}

void printDuplicateChar(const char *str)
{
    unsigned int length = strlen(str);

    unsigned int count[26];

    char c;

    printf("length :%u\n", length);

    memset(count, 0, sizeof(count));

    for (int i = 0; i < length; i++)
    {
        c = *(str + i);

        c = toupper(c);
        if (c <= 'Z' && c >= 'A')
        {
            count[c - 'A']++;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 1)
        {
            printf("%c : %d\n", (i+'A'), count[i]);
        }
    }
    return;
}
