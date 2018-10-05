# How can a given string be reversed using recursion?

### Solution:
### 1. Print the last character and assign it to \0 (EOL), recursive.
```
void reverseStringRecursion_1(char str[], char result[])
{
    if (str[0] != '\0')
    {
        *result = str[length - 1];
        str[length - 1] = '\0';
        reverseStringRecursion_1(str, result+1);
    }
}
```

### 2. Swap a couple of character, recursive
```
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
```
