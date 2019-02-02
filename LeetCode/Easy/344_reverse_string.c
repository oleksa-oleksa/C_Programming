/* Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.*/

char* reverseString(char *s)
{
	int i;
	char *tmpLast = s; 
	char CopyItem;
	char *tmpFirst = tmpLast;

	while (*tmpLast)
		tmpLast++; 
	tmpLast--;

	while (tmpFirst < tmpLast)
	{
		
		CopyItem = *tmpFirst;
		*tmpFirst = *tmpLast;
		*tmpLast = CopyItem;
		tmpFirst++;
		tmpLast--;
	}
	
	return s;
	
}
