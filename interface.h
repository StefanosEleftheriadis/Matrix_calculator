#include <iostream>

const int MAX_ROW=50;
const int MAX_COL=50;

class Matrix
{
	public:
		Matrix();
		void ReadMatrix(char Numtable);
		void PrintMatrix();
		bool AddSubtract(char symbol,Matrix matrix1,Matrix matrix2);
		bool Multiply(Matrix matrix1,Matrix matrix2);
		float Inverse(Matrix matrix);
		void getCofactor(float Arr[MAX_ROW][MAX_COL], float temp[MAX_ROW][MAX_COL], int pcount, int qcount, int ncount);
		float det(float det_arr[MAX_ROW][MAX_COL],int Ncounter);
		void adj(float mat_arr[MAX_ROW][MAX_COL],float adjoint[MAX_ROW][MAX_COL]);
	private:
		int row;
		int col;
		float mat[MAX_ROW][MAX_COL];
};
