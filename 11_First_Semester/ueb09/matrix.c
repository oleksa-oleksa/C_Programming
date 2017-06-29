#include <stdio.h>
#include "escapesequenzen.h"
#include "matrix.h"
#include "tools.h"

// The maximal size of all matrixes.
int getOneNumber (int Row, int Col, int i, int j, int ColCount, int Matrix[MaxRows][MaxColumns]);


/***************************************
*Deletes a wrong input
*Restores right numbers from Matrix
*Restores Matrix´s frame
***************************************/
void PrintLine (int Row, int Col, int i, int j, int ColCount, int Matrix[MaxRows][MaxColumns]);


//******************************************

int const MaxRows = 10;
int const MaxColumns = 10;
int Row, Col, MatrixNo, NumberOfRows, NumberOfCols, Num;

// Fragt den Benutzer nach der Anzahl der Matrixteilen
int getNumberOfRows (int Row, int Col, int MatrixNo)
{
	unsigned short readNumbers;

	do
	{	
		POSITION (Row,Col);
		printf("Geben Sie bitte die Zeilenanzahl der %i.Matrix ein (1..%i): _____", MatrixNo, MaxRows);
		POSITION(Row, 59);
		readNumbers = scanf("%i", &NumberOfRows); // read a number of rows
		clearBuffer();

		// checks if the Row <= MaxRows
		if (readNumbers == 1) 
		{
			if (NumberOfRows > 0 && NumberOfRows <= MaxRows)
				return NumberOfRows;
			else
			{
				CLEAR_LINE;
				readNumbers = 0;
			}
		}

		else
		{
			CLEAR_LINE;
			readNumbers = 0;
		}	

	} while (!readNumbers);
	return NumberOfRows;
}

// Fragt nach der Anzahl der Matrixspalten
int getNumberOfColumns (int Row, int Col, int MatrixNo)
{
	unsigned short readNumbers;

	do
	{	
		POSITION (Row,Col);
		printf("Geben Sie bitte die Spaltenanzahl der %i.Matrix ein (1..%i): _____", MatrixNo, MaxColumns);
		POSITION(Row, 60);
		readNumbers = scanf("%i", &NumberOfCols); // read a number of rows
		clearBuffer();

		// checks if the Row <= MaxRows
		if (readNumbers == 1) 
		{
			if (NumberOfCols > 0 && NumberOfCols <= MaxColumns)
				return NumberOfCols;
			else
			{
				CLEAR_LINE;
				readNumbers = 0;
			}
		}

		else
		{
			CLEAR_LINE;
			readNumbers = 0;
		}	

	} while (!readNumbers);
	return NumberOfCols;
}

void getMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns])
{
	int i, j, PositionCountR, PositionCountC;
	
	POSITION (Row, Col);
	PositionCountR = Row;


	// Prints an empty matrix
	for (i = 0; i < RowCount; i++)
	{
		POSITION (PositionCountR, 1);
		printf("|"); // Left vertical line
		for (j = 0; j < ColCount; j++)
			printf("    _"); // Underlie is at 7
		printf("  |\n"); // Right vertical line
		POSITION (++PositionCountR, 1);
	}

	// Reads matrix´s digits for each position
	
	POSITION (Row, Col);
	PositionCountR = Row;

	for (i = 0; i < RowCount; i++)
	{
		PositionCountC = 6;
		for (j = 0; j < ColCount; j++)
		{
   		    POSITION (PositionCountR, PositionCountC);

			Matrix[i][j] = getOneNumber(PositionCountR, PositionCountC, i, j, ColCount, Matrix);
			
			PrintLine(PositionCountR, 1, i, j+1, ColCount, Matrix);
			PositionCountC += 5;
		}

		++PositionCountR;
	}

}

int getOneNumber (int Row, int Col, int i, int j, int ColCount, int Matrix[MaxRows][MaxColumns])
{
	unsigned short readNumbers;
	int Num;

	do
	{
		readNumbers = scanf("%i", &Num);
		clearBuffer();

		if (readNumbers)
		{
			
			if (Num < -999 || Num > 9999)
			{

			PrintLine(Row, 1, i, j, ColCount, Matrix);

			readNumbers = 0;

			POSITION (Row, Col);
			}

			else
				return Num;
		}

		else
		{
			PrintLine(Row, 1, i, j, ColCount, Matrix);

			readNumbers = 0;

			POSITION (Row, Col);

		}


	} while (!readNumbers);

	return Num;
}

void PrintLine (int Row, int Col, int i, int j, int ColCount, int Matrix[MaxRows][MaxColumns])
{
	int sw; // for loop´s counter
	POSITION (Row, Col);
	CLEAR_LINE;	
	printf("|"); // Left vertical line
	
	for (sw = 0; sw < j; sw++)
	{
		printf("%5i", Matrix[i][sw]);

	}

	for (sw = j; sw < ColCount; sw++)
	{
		printf("    _");	
	}
	 
	printf("  |"); // Right vertical line
	POSITION (Row, Col);
}

void calcMatrix(int RowCount1, int ColCount1, int ColCount2, int M1[MaxRows][MaxColumns], int M2[MaxRows][MaxColumns], int MErg[MaxRows][MaxColumns])
{
	int count, Mult, iErg, jErg;
	// Getting inside the MErg
	for (iErg = 0; iErg < RowCount1; iErg++)
	{
		for (jErg = 0; jErg < ColCount2; jErg++)
		{
			// Going through two matrixes for calculation the element od MErg

			int Sum = 0;

			for (count = 0; count < ColCount1; count++)
			{
				Mult = M1[iErg][count] * M2[count][jErg];
				Sum += Mult;

			}

			MErg[iErg][jErg] = Sum;
		}

	}
}

void printMatrix(int Row, int Col, int RowCount, int ColCount, int Matrix[MaxRows][MaxColumns])
{
	int i;
	POSITION (Row, Col);

	for (i = 0; i < RowCount; i++)
	{
		PrintLine(Row, Col, i, ColCount, ColCount, Matrix);
		++Row;
	}
}
