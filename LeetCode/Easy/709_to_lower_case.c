/*
Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.

Example 1:
Input: "Hello"
Output: "hello"

Example 2:
Input: "here"
Output: "here"
 */

char * toLowerCase(char * str){
    char *tmpLower = str;
    
    while (*tmpLower) {
        if (*tmpLower >= 65 && *tmpLower <= 90) {
            *tmpLower = *tmpLower + 32;
        }
        *tmpLower++;
    }
    return str;
}