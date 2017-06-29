#include <stdio.h>
#include "escapesequenzen.h"

void clearBuffer();
int askAgain (int Row, int Col);

void clearBuffer ()
{
	char RestInput; // for keeping the garbage from Buffer
	do
		scanf("%c", &RestInput);
	while (RestInput != '\n');
}


int askAgain (int Row, int Col)
{

	POSITION (Row, Col);
  	char iWantQuit;

  
  	do // Loop for asking unill a correct char is given
    {

      printf("Wollen Sie noch einmal berechnen? (j/n): \n");
      

      scanf("%[^\n]", &iWantQuit);

      if (iWantQuit == '\n')
        clearBuffer();

      clearBuffer();

      if (iWantQuit == 'j' || iWantQuit == 'J') {
        return 1;
      } else if (iWantQuit == 'n' || iWantQuit == 'N') {
        return 0;
      }
    } while (1);
}
