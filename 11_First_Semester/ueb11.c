#include <stdio.h>
#include "text.h"
#include "tools.h"
#include "escapesequenzen.h"

int main ()
{
	int const MaxLength = 201;      // max. Laenge des Eingabesatzes + 1 fuer '\0'   
	char EnteredText[MaxLength];    // Zeichenkette fuer Texteingabe   
	int Width, Row, Col;                     // Breite des auszugebenen Textes

	do
	{
		Row = 1; // Set initial position
		Col = 1;

		CLEAR;      
		HOME; 

		resetArray(EnteredText, MaxLength);
    
		printf("Textanzeige mit variabler Breite\n\n");
		getText("Geben Sie bitte den Text ein (min. 1 Zeichen; max. 200 Zeichen):\n", EnteredText, &Row, &Col);      
		printf("\n");
		getWidth("In welcher maximalen Breite soll der Text ausgegeben werden (%i-%i): ", 10, 79, &Width); 
		printText(EnteredText, Width, MaxLength);

	} while (askAgain(23, 1));
return 0;
}