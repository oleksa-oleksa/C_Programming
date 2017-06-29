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
