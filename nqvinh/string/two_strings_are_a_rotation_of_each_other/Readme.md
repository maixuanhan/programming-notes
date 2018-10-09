# How do you check if two strings are a rotation of each other?

### Solution: duplicate sourch string, a rolation string will exist on new duplicated string if any. Pass the new string for checking.



### Example:
```
stringSource  = "quang vinh";
string2       = "inhquang v";
string3       = "ang vinhqu";
string4       = "vinhquang ";

duplicateString = "quang vinhquang vinh"
```
### All of string2, string3, string4 are rolation version of source string and also be in duplicateString.
