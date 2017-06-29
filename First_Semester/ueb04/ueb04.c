#include <stdio.h>
#include <math.h>
// Das Programm loest die quadratische Gleichungen
// Die beide Faktoren p und q muss von Benutzer eingegeben werden sein.

int main ()
{
  double p, q, x1, x2, unterwurzel;

  printf("\n|-----------------------------------------------------------------------|\n");
  printf("| Dieses Programm loest eine quadratische Gleichung zweiten Grades:     |\n");
  printf("| x^2 + p * x + q = 0                                                   |\n");
  printf("|                                                                       |\n");
  printf("| Geben Sie bitte die Faktoren p und q ein:                             |\n");
  printf("|-----------------------------------------------------------------------|\n");

  // Eingabe der Faktoren

  printf("\np = ");
  scanf("%lf", &p);

  printf("\nq = ");
  scanf("%lf", &q);

  printf("\n|-----------------------------------------------------------------------|\n");
  printf("| Es wird nun fur die quadratische Gleichung zweiten Grad               |\n");
  printf("| x^2 + %8.2f * x + %8.2f = 0                                     |\n", p,q);
  printf("|die Loesung gefunden...                                                |\n");
  printf("|                                 _____________________________         |\n");
  printf("|           1              +     /   %8.2f ^ 2              \\        |\n", p);
  printf("| x    = - ---  *%8.2f  - \\  /  ----------------  - %-8.2f         |\n", p, q);
  printf("|  1,2      2                 \\/          4                             |\n");
  printf("|                                                                       |\n");

  // Teil der Berechnungen
  // Zuerst muss man feststellen ob uberhaupt die Loesungen gibt

  unterwurzel = p*p / 4 - q;

  if (unterwurzel < 0) 
  {
    printf("| Diese Gleichung hat uberhaupt KEINE Loesungen!                        |\n");
    printf("|                                                                       |\n");
  } // If statement is closed
  
  else 
  {
    if (unterwurzel == 0) 
    {
      x1 = (-p) / 2;
      printf("| Diese Gleichung hat nur eine Loesung:                                 |\n");
      printf("|                                                                       |\n");  
      printf("| x1 = x2 = %-8.2f                                                    |\n", x1);
    } 
 
    else 
    {
      x1 = (-p) / 2 + sqrt (unterwurzel);
      x2 = (-p) / 2 - sqrt (unterwurzel);
      printf("| x1 = %-8.2f                                                         |\n", x1);
      printf("| x2 = %-8.2f                                                         |\n", x2);
    }
  } // Else statment is closed

  printf("|-----------------------------------------------------------------------|\n");

  return 0;
}

