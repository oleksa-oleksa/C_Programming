#ifndef TEXT_H
	#define TEXT_H TEXT_H

	void getText(char InfoText[], char *EnteredText, int *Row, int *Col);

	void getWidth(char InfoText[], int a, int b, int *Width);

	void printText (char *EnteredText, int Width, int MaxLength);

	void resetArray(char *A, int MaxLength);

#endif