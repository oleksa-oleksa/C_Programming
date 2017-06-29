/* This program reads an integer number from user
and gives it back to a screen.*/

#include <stdio.h>
int main ()
{
   int Digit;
   char Rest, Exit;

   printf("Dieses Programm liest eine ganze Zahl vom Benutzer ein ");
   printf("und wieder auf den Bildschirm ausgibt. \n");

   // Loop for reading the digit
   do
   {
      printf("Geben Sie bitte eine ganze Zahl ein:\n");

      // Tests if the digit was entered correct
      // Scanf gives back 0 or 1 as result 

      if (scanf("%d", &Digit) == 1)
         printf("Sie haben die Zahl %d eingegeben!\n\n", Digit);
      else
      {
         printf("Eine falsche Eingabe! Bitte geben Sie eine ganze Zahl.\n");
      
      } 
     
      // Deletes the buffer after the user has entered the Digit
      do
      {
         scanf("%c", &Rest);
      } while (Rest != '\n');

      printf("Wollen Sie noch einmal das Programm benutzen?\n");
      printf("Geben Sie bitte ein: (j/n)?\n");

      // Tests the exit conditions      
      do
      {
      scanf("%c", &Exit);
      if (Exit =='N' || Exit == 'n')
      {   
         printf("Das Program wird beendet...\n");
      }
      else
      {
         if (Exit == 'J' || Exit == 'j')
         {
            printf("Programm wird gestartet\n\n");
         }
         else
         {
            printf("Das Program erwartet auf nur 'n' oder 'j'.\n");
            printf("Bitte geben Sie die richtige Eingabe:\n");
         }
      }  
      // Deletes the buffer after user has entered the answer j/n
      do
          {
             scanf("%c", &Rest);
          } while (Rest != '\n');

      } while (Exit !='N' &&  Exit != 'n' && Exit != 'J' && Exit != 'j');
   } 
   // Condition for exiting from loop
   while (Exit != 'n' && Exit != 'N');
   return 0;
}   
