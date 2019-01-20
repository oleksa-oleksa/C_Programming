#include <stdio.h>
#include "escapesequenzen.h"

void clearBuffer ();
short getNumber(int Zeile);
void printBinary(short Zahl);
void printInputNumber(int Zeile, short Zahl);
char getOperator(int Zeile);
void printInputOperator(int Zeile, char Op);
short calcResult(short z1, short z2, char op);
void printResultNumber(int Zeile, short Zahl);
int askAgain();
void printFrame ();

int main()
{
  unsigned short z1, z2, res; // First and second Operand, Result 
  char op; // Bit-Operator as a character for next interpretation in foo
  
  // Loop of a main programm
  do 
  {
    printFrame();

    z1 = getNumber(4); // Zahl1 is on a 4 row is entered
    printInputNumber(11, z1); // Row 11 os for output of Zahl2

    op = getOperator(5);
    printInputOperator(12, op);

    z2 = getNumber(6);
    printInputNumber(13, z2);

    res = calcResult(z1, z2, op);

    printResultNumber(15, res);
  } while(askAgain());

  CLEAR;
  HOME;
  return 0;
}

// Cleans Buffer after scanf
void clearBuffer ()
{
  char RestInput; // swap for extra signs
    do
      scanf("%c", &RestInput);
    while (RestInput != '\n');
}


// reads an operand (first and second, it depends)
short getNumber(int Zeile)
{
  unsigned short number, readNumbers;
  while(1)
  {
    POSITION(Zeile, 18); // 18 vertical position 
    printf("                       "); // deletes a previous output
    POSITION(Zeile, 18); // reposition at the same place

    readNumbers = scanf("%hu", &number); // read a a short whole num
    clearBuffer();

    if (readNumbers == 1) // if was entered a digit
      return number; // then gives 1 => condition for an exit 
  }
}


void printBinary(short Zahl)
{
  for (int i = 0; i < 16; i++) 
  {
    if (Zahl & 0x8000)
      printf("1");
    else
      printf("0");

    Zahl = Zahl << 1;
  }
}

void printInputNumber(int Zeile, short Zahl)
{
  POSITION(Zeile, 14);
  printf("%6hd", Zahl); // decimal

  POSITION(Zeile, 23); // octal
  printf("%#7ho", Zahl);

  POSITION(Zeile, 33); // Hexadecimal
  printf("%#06hx", Zahl);

  POSITION(Zeile, 42); 
  printBinary(Zahl); // Calls Binary Convertor
}

char getOperator(int Zeile)
{
  char Op;
  int readNumbers;
  do
  {
    POSITION(Zeile, 18);
    printf("                       "); // clears the screen
    POSITION(Zeile, 18);

    readNumbers = scanf("%c", &Op); // if was entered, readNumbers = true
    clearBuffer();

    if (Op == '&' || Op == '|' || Op == '^' || Op == '<' || Op == '>' || Op == '%') // checks for corect input
      return Op;
    else
       readNumbers = 0;
  } while (!readNumbers); // !1 = 0 => exit 

}


void printInputOperator(int Zeile, char Op)
{
  POSITION(Zeile, 18);

  switch(Op) {
  case '<':
    printf("<< |      << |     << |               <<  |"); // convertin < to <<
    break;
  case '>':
    printf(">> |      >> |     >> |               >>  |");
    break;
  default:
    printf(" %c |       %c |      %c |                %c  |", Op, Op, Op, Op); // other operators
  }

}

// Mathematical part is here
short calcResult(short z1, short z2, char op)
{
  switch(op)
  {
  case '&':
    return z1 & z2;
  case '|':
    return z1 | z2;
  case '^':
    return z1 ^ z2;
  case '<':
    return z1 << z2;
  case '>':
    return z1 >> z2;
  case '%':
    return z1 % z2;
  }
}

// chosse position and printing a resulr, idea is the same as printInput
void printResultNumber(int Zeile, short Zahl)
{
  POSITION(Zeile, 14);
  printf("%6hd", Zahl);

  POSITION(Zeile, 23);
  printf("%#7ho", Zahl);

  POSITION(Zeile, 33);
  printf("%#06hx", Zahl);

  POSITION(Zeile, 42);
  printBinary(Zahl);
}


// Asks if user want to continue one more time
int askAgain()
{
  char iWantQuit;

  POSITION(18, 0);

  do // Loop for asking unill a correct char is given
    {

      printf("Wollen Sie noch einmal berechnen?\n");
      printf("Bitte geben Sie \"j\" oder \"n\" ein: \n");

      scanf("%c", &iWantQuit);

      clearBuffer();

      if (iWantQuit == 'j' || iWantQuit == 'J') {
        return 1;
      } else if (iWantQuit == 'n' || iWantQuit == 'N') {
        return 0;
      }
    } while (1);
}

// Here is Art
// Deletes a previos screen
// Draws a table witout variables 
// Variables are insered with a help of another funktion
void printFrame ()
{
  CLEAR;                      // Bildschirm löschen
  HOME;
  printf("|----------------------------------------------------------|\n");
  printf("| Bitoperatoren-Rechner                                    |\n");
  printf("|                                                          |\n");
  printf("| Eingabe Zahl 1:                                          |\n");
  printf("| Operator:                                                |\n");
  printf("| Eingabe Zahl 2:                                          |\n");
  printf("|                                                          |\n");
  printf("|----------------------------------------------------------|\n");
  printf("|                                                          |\n");
  printf("|          |  dez.  |  okt.   |  hex.  | Binaerdarstellung |\n");
  printf("| Zahl 1   |        |         |        |                   |\n");
  printf("| Operator |        |         |        |                   |\n");
  printf("| Zahl 2   |        |         |        |                   |\n");
  printf("|----------------------------------------------------------|\n");
  printf("| Ergebnis |        |         |        |                   |\n");
  printf("|----------------------------------------------------------|\n");

}


