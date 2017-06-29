#include <stdio.h>

/* Die Programm berechnet einen Gesamtwiderstand bei Reihen- und Parallelschaltung sowie
   der unbekannte Widerstand in einer Wheatstoneschen Messbrücke 
*/

int main () 
{
	double Rges =   0.0; // Gesammtwiderstand zu berecnen
	double R1   = 500.0, // 3 vorgegebene Widerstaende
          R2   = 200.0, 
          R3   = 300.0;
	
	printf("\nDieses Programm berechnet aus 3 Werten \n");
	printf("\nReihenschaltung:\n");
	Rges = R1 + R2 + R3;
	printf("%f", R1);
	printf(" Ohm + %f", R2);
	printf(" Ohm + %f", R3);
	printf(" Ohm = %f", Rges);
	printf(" Ohm\n");

	printf("\n\nParallelschaltung:\n");
	Rges = 1 / (1 / R1 + 1 / R2 + 1 / R3);
	printf("1 / %f", R1);
 	printf(" Ohm + 1 / %f", R2);
	printf(" Ohm + 1 / %f", R3);
	printf(" Ohm = 1 / %f", Rges);
	printf(" Ohm\n");

	printf("\nWheatstonesche Messbruecke:\n");
	Rges = (R3 * R1) / R2;
	printf("%f", R3);
 	printf(" Ohm * %f", R1);
	printf(" Ohm / %f", R2);
	printf(" Ohm = %f", Rges);
	printf(" Ohm\n");

	printf("\nAlle drei Widerstaende sind berechnet\n\n");
	
	return 0;
}
