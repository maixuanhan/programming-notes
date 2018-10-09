#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool isRolation(const char *str_1, const char *str_2);
bool checkEqual_UInt(unsigned int a, unsigned int b);
bool checkEqual_Char(char a, char b);
void duplicateAString(const char *str, char *str_result, unsigned int strLen, unsigned int strLen_result);

int main(int argc, char const *argv[])
{
    char *string  = "quang vinh";
    char *string2 = "inhquang v";
    isRolation(string, string2) ? printf("TRUE\n") : printf("FALSE\n");
    return 0;
}

bool isRolation(const char *str_1, const char *str_2)
{
    unsigned int lengthStr1        = strlen(str_1);
    unsigned int lengthStr2        = strlen(str_2);
    unsigned int lengthDupStr      = 0;
    bool resultFlag                = false;
    unsigned int numberCharMatched = 0;

    if (!checkEqual_UInt(lengthStr1, lengthStr2))
    {
        printf("Failed in: %s line: %d\n", __FUNCTION__, __LINE__ );
        return false;
    }

    char duplicatedStr[lengthStr1*2];
    memset(duplicatedStr, 0, sizeof(duplicatedStr));

    duplicateAString(str_1, duplicatedStr, lengthStr1, lengthStr1*2);

    lengthDupStr = strlen(duplicatedStr);

    for (int i = 0; i < lengthDupStr; i++)
    {
        if (checkEqual_Char(str_2[0], duplicatedStr[i]))
        {
            for (int j = 0; j < lengthStr2; j++)
            {
                if (checkEqual_Char(str_2[0 + j], duplicatedStr[i + j]))
                {
                    numberCharMatched++;
                }
            }

            if (checkEqual_UInt(numberCharMatched, lengthStr2))
            {
                resultFlag = true;
                break;
            }
            else
            {
                resultFlag = false;
                numberCharMatched = 0;
            }
        }
    }

    return resultFlag;
}

bool checkEqual_UInt(unsigned int a, unsigned int b)
{
    return (a == b) ? true : false;
}

bool checkEqual_Char(char a, char b)
{
    return (a == b) ? true : false;
}

void duplicateAString(const char *str, char *str_result, unsigned int strLen, unsigned int strLen_result)
{
    unsigned int n = 0;
    for (int a = 0; a < 2; a++)
    {
        for (int i = 0; i < strLen; i++, n++)
        {
            str_result[n] = str[i];
        }
    }
    str_result[n] = '\0';
}
