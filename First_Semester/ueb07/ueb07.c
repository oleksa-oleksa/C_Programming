#include <stdio.h>
#include "escapesequenzen.h"

int main ()
{
   double Operand1, Operand2, Result; // for calculator
   int MenuSelection; // define user choise
   int CorrectInput, CorrectOp; //checks if a digit was entered
   char RestInput; // clears garbage from memory

   do
   {
      // Shows menu selection option on a screen
      
      printf("Einfacher Taschenrechner\n");
      printf("========================\n\n");
      printf("Bitte waehlen Sie die Zahl:\n\n");
      printf("1. Addition\n");
      printf("2. Subtraktion\n");
      printf("3. Multiplikation\n");
      printf("4. Division\n");
      printf("9. Programm beenden\n\n");

      // User enters a number of operation
      
      printf("Ihre Wahl ist: \n");
         
      //scanf returns "false" if no digit was entered
      CorrectInput = scanf("%i", &MenuSelection);

      // Loop deletes the extra symbols from memory
      do
            scanf("%c", &RestInput);
      while (RestInput != '\n');

      if (CorrectInput) // if digit was entered, scanf return 1 ==> true
      {                 // then check whether digit was entered correct
         switch(MenuSelection) // switchs to choosen mathematical operation
         {
            case 1: printf("Addition \n-------------------\n"); break;
            case 2: printf("Subtraktion\n---------------\n"); break;
            case 3: printf("Multiplikation\n----------------\n"); break;
            case 4: printf("Division\n----------------\n"); break;
            default: CorrectInput = 0;
         }
     
         // If User does NOT want to exit 
         if (CorrectInput)
         {

            // This part does sth only if a correct choise was made
            // Input for Operand1
            do
            {
               printf("Bitte geben Sie erste Zahl ein: \n\n");
               printf("Erste Zahl ist:\n");

               CorrectOp = scanf("%lf", &Operand1);
               printf("\n");

               // Loop deletes the extra symbols from memory
               do
                  scanf("%c", &RestInput);
               while (RestInput != '\n');

               if (!CorrectOp)
                  printf("Bitte geben Sie eine Zahl ein! Keine Buchstaben, Leerzeichen...\n");

            } while (!CorrectOp);

            // Input for Operand2
            do
            {
               printf("Bitte geben Sie zweite Zahl ein: \n\n");
               printf("Zweite Zahl ist:\n");

               CorrectOp = scanf("%lf", &Operand2);
               printf("\n");

               // Loop deletes the extra symbols from memory
               do
                  scanf("%c", &RestInput);
               while (RestInput != '\n');

               if (!CorrectOp)
                  printf("Bitte geben Sie eine Zahl ein! Keine Buchstaben, Leerzeichen...\n");

               else
               {
                  // checks if a zero was entered to avoid an error
                  if (MenuSelection == 4 && Operand2 == 0)
                  {
                     printf("Division durch Null ist nicht erlaubt.\n");
                     printf("Die Antwort ist \"Unendlichkeit\"!\n");
                     printf("Das Rechner braucht eine andere Zahl...\n");
                     CorrectOp = 0;
                  }
               }
            } while (!CorrectOp);
         }
         switch (MenuSelection) // the core of calculator :)
         {
            case 1:  Result = Operand1 + Operand2; 
                     printf("%.2lf + %.2lf wird berechnet\n", Operand1, Operand2);
                     printf("Result ist: %.2lf\n\n", Result);
                     break;
            case 2:  Result = Operand1 - Operand2; 
                     printf("%.2lf - %.2lf wird berechnet\n", Operand1, Operand2);
                     printf("Result ist: %.2lf\n\n", Result);
                     break;
            case 3:  Result = Operand1 * Operand2; 
                     printf("%.2lf * %.2lf wird berechnet\n", Operand1, Operand2);
                     printf("Result ist: %.2lf\n\n", Result);
                     break;
            case 4:  Result = Operand1 / Operand2; 
                     printf("%.2lf / %.2lf wird berechnet\n", Operand1, Operand2);
                     printf("Result ist: %.2lf\n\n", Result);
                     break;

            case 9:  break;

            default: printf("Bitte geben Sie eine Zahl (1,2,3,4 oder 9) ein! \n\n");
         }
      }
      else
      {
         printf("Bitte geben Sie eine Zahl (1,2,3,4 oder 9) ein!\n");
         CorrectInput = 0;
      }
      // Enter key
      printf("Bitte Eingabetaste druecken...\n");
      // Loop deletes the extra symbols from memory
      do
         scanf("%c", &RestInput);
      while (RestInput != '\n');
    
   } while (MenuSelection != 9); // while user has not 9 entered - repeat

   printf("Program wird beendet\n");
   return 0;
}
