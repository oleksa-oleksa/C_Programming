#include <stdio.h>
#include "escapesequenzen.h"
#include "matrix.h"
#include "tools.h"

int main()
{
   int Matrix1[MaxRows][MaxColumns];
   int Matrix2[MaxRows][MaxColumns];
   int MatrixErg[MaxRows][MaxColumns];
   int AnzZeilen1, AnzSpalten1;
   int AnzZeilen2, AnzSpalten2;
   int AnzZeilenErg, AnzSpaltenErg;

   do
   {
      CLEAR;
      HOME;

      AnzZeilen1 = getNumberOfRows(1, 1, 1);
      AnzSpalten1 = getNumberOfColumns(2, 1, 1);
      getMatrix(4, 1, AnzZeilen1, AnzSpalten1, Matrix1);

      AnzZeilen2 = AnzSpalten1;
      AnzSpalten2 = getNumberOfColumns(5 + AnzZeilen1, 1, 2);
      getMatrix(6 + AnzZeilen1, 1, AnzZeilen2, AnzSpalten2, Matrix2);

      AnzZeilenErg = AnzZeilen1;
      AnzSpaltenErg = AnzSpalten2;
      calcMatrix(AnzZeilen1, AnzSpalten1, AnzSpalten2, Matrix1, Matrix2, MatrixErg);

      CLEAR;
      HOME;
      printMatrix(1,  1, AnzZeilen1, AnzSpalten1, Matrix1);
      POSITION((AnzZeilen1 + AnzZeilen2) / 4 + 1, AnzSpalten1 * 5 + 6);
      printf("*");
      printMatrix(1, AnzSpalten1 * 5 + 9, AnzZeilen2, AnzSpalten2, Matrix2);
      POSITION((AnzZeilen1 + AnzZeilen2) / 4 + 1, (AnzSpalten1 + AnzSpalten2) * 5 + 14);
      printf("=");
      printMatrix(1, (AnzSpalten1 + AnzSpalten2) * 5 + 17, AnzZeilenErg, AnzSpaltenErg, MatrixErg);
   } while (askAgain(2 + ((AnzZeilen1 > AnzZeilen2) ? AnzZeilen1 : AnzZeilen2), 1));
   CLEAR;
   HOME; 
   printf("Programm wurde beendet!\n\n");
   return 0;
}
