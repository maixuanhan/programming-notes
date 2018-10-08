#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define ALPHABET 26

struct charInfomation_s
{
    char         letter;
    unsigned int count;
    unsigned int firstMeet;
};

struct charInfomation_s printFirstNonRepeated_char(const char *str);

int main(int argc, char const *argv[])
{
    char *string = "Cong hoa xa hoi chu nghia viet nam, doc lap tu do hanh phuc";
    struct charInfomation_s firstNonRepeatedChar;

    firstNonRepeatedChar = printFirstNonRepeated_char(string);
    if (firstNonRepeatedChar.letter != 0)
    {
        printf("First Non Repeated Char: %c at %d\n", firstNonRepeatedChar.letter, firstNonRepeatedChar.firstMeet); // print x is right result.
    }
    else
    {
        printf("All Characters are repeated\n");
    }

    return 0;
}

struct charInfomation_s printFirstNonRepeated_char(const char *str)
{
    unsigned int length = strlen(str);
    struct charInfomation_s charInfo[ALPHABET];
    char c = 0;
    struct charInfomation_s mark = {0,0,0};
    bool flag = false;

    memset(charInfo, 0, sizeof(struct charInfomation_s)*ALPHABET);

    for (int i = 0; i < length; i++)
    {
        c = toupper(str[i]);
        if (c <= 'Z' && c >= 'A') // C=[A, Z] ~ c=[64, 90]
        {
            charInfo[c - 'A'].letter = c; // charInfo[0].letter = 65, charInfo[1].letter = 66,...,charInfo[25].letter = 90
            charInfo[c - 'A'].count++;
            if (charInfo[c - 'A'].firstMeet == 0)
            {
                charInfo[c - 'A'].firstMeet = i;
            }
        }
    }

    for (int i = 0; i < ALPHABET; ++i)
    {
        if (charInfo[i].count == 1) // nonrepeat
        {
            if (!flag)
            {
                flag = true;
                mark = charInfo[i];
            }
            else
            {
                if (mark.firstMeet > charInfo[i].firstMeet)
                {
                    mark.letter = charInfo[i].letter;
                    mark.firstMeet = charInfo[i].firstMeet;
                }
            }
        }
    }

    return mark;
}
