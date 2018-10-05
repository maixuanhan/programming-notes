#include <string.h>
#include <stdio.h>


/*
    4. How can a given string be reversed using recursion?
*/

void reverseStringRecursion_1(char str[], char result[]);
void reverseStringRecursion_2(char str[], int idx1, int idx2);
void swap(char *a, char *b);

int main(int argc, char const *argv[])
{
    char string[]  = "Cong hoa";
    char string2[] = "Cong hoa";
    char result[255];
    memset(result , 0, sizeof(result));
    reverseStringRecursion_1(string, result);
    printf("%s\n", result);

    reverseStringRecursion_2(string2, 0, strlen(string2)-1);
    printf("%s\n", string2);

    return 0;
}


void reverseStringRecursion_1(char str[], char result[])
{
    long unsigned int length = strlen(str);

    if (str[0] != '\0')
    {
        *result = str[length - 1];
        str[length - 1] = '\0';
        reverseStringRecursion_1(str, result+1);
    }
}


void reverseStringRecursion_2(char str[], int idx1, int idx2)
{
    if (idx1 < idx2)
    {
        swap(&str[idx1], &str[idx2]);
        idx1++;
        idx2--;
        reverseStringRecursion_2(str, idx1, idx2);
    }
}

void swap(char *a, char *b)
{
    char tmp = 0;

    tmp = *a;
    *a  = *b;
    *b  = tmp;

    return;
}
