#ifndef MATRIX_H
   #define MATRIX_H MATRIX_H

   /***************************************************************************
    * maximale Groesse der Matrizen
    ***************************************************************************/
   extern int const MaxRows, MaxColumns;

   /***************************************************************************
    *  getNumberOfRows
    *  Fragt den Benutzer nach der Anzahl der Matrixzeilen
    *  Parameter: Row, Col: Zeile und Spalte, in der die Benutzerfrage beginnt
    *             MatrixNo: Nr. der Matrix, fuer die nach der Zeilenanzahl gefragt wird
    *  Ergebnis : Gibt die Anzahl der Matrixzeilen zurueck
    *             (ist garantiert eine Zahl zwischen 1 und MaxRows!)
    ***************************************************************************/
   int getNumberOfRows(int Row, int Col, int MatrixNo);

   /***************************************************************************
    *  getNumberOfColumns
    *  Fragt den Benutzer nach der Anzahl der Matrixspalten
    *  Parameter: Row, Col: Zeile und Spalte, in der die Benutzerfrage beginnt
    *             MatrixNo: Nr. der Matrix, fuer die nach der Spaltenanzahl gefragt wird
    *  Ergebnis : Gibt die Anzahl der Matrixspalten zurueck
    *             (ist garantiert eine Zahl zwischen 1 und MaxColumns!)
    ***************************************************************************/
   int getNumberOfColumns(int Row, int Col, int MatrixNo);

   /***************************************************************************
    *  getMatrix
    *  Schreibt eine leere Matrix auf den Bildschirm (fuer die Zahlen werden
    *  erst einmal Unterstriche geschrieben). Dann werden die Werte der Matrix
    *  zeilenweise an den entsprechenden Positionen in der Matrix vom Benutzer
    *  erfragt. Jeweils nach der Eingabe einer Zahl wird diese gleich noch
    *  einmal formatiert an die entsprechende Position geschrieben.
    *  Die Zahlen in der Matrix duerfen maximal vier Zeichen lang sein
    *  (d.h. die Zahlen duerfen nur im Bereich von -999 bis 9999 liegen!)
    *  Parameter: Row, Col: Zeile und Spalte, in der die Matrix auf dem Bildschirm beginnt
    *             RowCount, ColCount: Zeilen- und Spaltenanzahl der genutzten Matrix
    *             Matrix: Matrix, fuer die die Zahlen eingelesen werden
    *  Ergebnis : nichts
    ***************************************************************************/
   void getMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns]);

   /***************************************************************************
    *  calcMatrix
    *  Multipliziert zwei Matrizen.
    *  Parameter: RowCount1, ColCount1: Zeilen- und Spaltenanzahl der ersten Matrix
    *             ColCount2: Spaltenanzahl der zweiten Matrix
    *             M1, M2: die Matrizen, die multipliziert werden
    *             MErg: Ergebnis-Matrix
    *  Ergebnis : nichts
    ***************************************************************************/
   void calcMatrix(int RowCount1, int ColCount1, int ColCount2, int M1[MaxRows][MaxColumns], int M2[MaxRows][MaxColumns], int MErg[MaxRows][MaxColumns]);

   /***************************************************************************
    *  printMatrix
    *  Gibt eine Matrix auf dem Bildschirm aus.
    *  Parameter: Row, Col: Zeile und Spalte, in der die Matrixausgabe beginnt
    *             RowCount, ColCount: Zeilen- und Spaltenanzahl der Matrix
    *             Matrix: Matrix, die auf dem Bildschirm ausgegeben werden soll
    *  Ergebnis : nichts
    ***************************************************************************/
   void printMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns]);

#endif
