//============================================================================
/*
Determine whether an integer is a palindrome. 
Do this without extra space.
*/
int isPalindrome(int x)
{
    
    int rev = 0;
    int num = abs (x);

    while (x != 0)
    {
        rev = rev * 10 + x % 10;
        x = x / 10;
    }
    
    if (rev == num)
        return 1;
    else 
        return 0;
}