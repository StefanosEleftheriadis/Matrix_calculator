#include <iostream>
#include <cmath>
#include <iomanip>
#include "interface.h"

using namespace std;

Matrix::Matrix()
{
	row=0;
	col=0;
}

void Matrix::ReadMatrix(char Numtable)
{
	cout<<"Enter Matrix "<<Numtable<<" rows: ";
	cin>>row;
	cout<<"Enter Matrix "<<Numtable<<" columns: ";
	cin>>col;
	
	for(int counterout=0;counterout<row;counterout++)
	{
		for(int counterin=0;counterin<col;counterin++)
		{
			cout<<"Enter Matrix"<<Numtable<<"["<<counterout<<"]["<<counterin<<"]: ";
			cin>>mat[counterout][counterin];
		}	
	}
	
}

void Matrix::PrintMatrix()
{
	for(int counterout=0;counterout<row;counterout++)
	{
		cout<<"[";
		for(int counterin=0;counterin<col;counterin++)
		{
			if(fabs(mat[counterout][counterin]-int(mat[counterout][counterin]))>0)
			{
				cout<<setw(15);
			}
			else
			{
				cout<<setw(5);
			}
			cout<<mat[counterout][counterin];
		}
		cout<<"]"<<endl;	
	}
}

bool Matrix::AddSubtract(char symbol,Matrix matrix1,Matrix matrix2)
{
	bool No_mult=false;
	if(matrix1.row==matrix2.row && matrix1.col==matrix2.col)
	{
		row=matrix1.row;
		col=matrix1.col;
		
		if(symbol=='+')
		{
			for(int counterout=0;counterout<row;counterout++)
			{
				for(int counterin=0;counterin<col;counterin++)
				{
					mat[counterout][counterin]=matrix1.mat[counterout][counterin]+matrix2.mat[counterout][counterin];
				}
			}
		}
		else if(symbol=='-')
		{
			for(int counterout=0;counterout<row;counterout++)
			{
				for(int counterin=0;counterin<col;counterin++)
				{
					mat[counterout][counterin]=matrix1.mat[counterout][counterin]-matrix2.mat[counterout][counterin];
				}
			}
		}
	}
	else
	{
		cout<<"MatrixA and MatrixB don't have the same size!"<<endl;
		No_mult=true;
	}
	
	return No_mult;
	
}

bool Matrix::Multiply(Matrix matrix1,Matrix matrix2)
{
	bool No_mult=false;
	if(matrix1.col==matrix2.row)
	{
		row=matrix1.row;
		col=matrix2.col;
		
		for(int counterout=0;counterout<row;counterout++)
		{
			for(int counterin=0;counterin<col;counterin++)
			{
				mat[counterout][counterin]=0.0;			
			}
		}
					
		for(int counterout=0;counterout<row;counterout++)
		{
			for(int counterin=0;counterin<col;counterin++)
			{
				for(int count_matrix=0;count_matrix<matrix1.col;count_matrix++)
				{
					mat[counterout][counterin]=matrix1.mat[counterout][count_matrix]*matrix2.mat[count_matrix][counterin]+mat[counterout][counterin];
				}
			
			}
		}
					
	}
	else
	{
		cout<<"MatrixA columns and MatrixB rows aren't the same!"<<endl;
		No_mult=true;
	}
	
	return No_mult;
	
}

void Matrix::adj(float mat_arr[MAX_ROW][MAX_COL],float adjoint[MAX_ROW][MAX_COL])
{
	float temp_arr[MAX_ROW][MAX_COL];
	int sign=1;
	
	for (int row_count=0; row_count<row; row_count++)
    {
        for (int col_count=0; col_count<col; col_count++)
        {
            // Get cofactor of A[i][j]
            getCofactor(mat_arr, temp_arr, row_count, col_count, row);
 
            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((row_count+col_count)%2==0)? 1: -1;
 
            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adjoint[col_count][row_count] = (sign)*(Matrix::det(temp_arr, row-1));
        }
    }
	
}

void Matrix::getCofactor(float Arr[MAX_ROW][MAX_COL], float temp[MAX_ROW][MAX_COL], int pcount, int qcount, int ncount)
{
    int icount = 0, jcount = 0;
 
    // Looping for each element of the matrix
    for (int row_count = 0; row_count < ncount; row_count++)
    {
        for (int col_count = 0; col_count < ncount; col_count++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row_count != pcount && col_count != qcount)
            {
                temp[icount][jcount++] = Arr[row_count][col_count];
 
                // Row is filled, so increase row index and
                // reset col index
                if (jcount == ncount - 1)
                {
                    jcount = 0;
                    icount++;
                }
            }
        }
    }
}

float Matrix::det(float det_arr[MAX_ROW][MAX_COL],int Ncounter)
{
	float Det=0.0;
	float temp_arr[MAX_ROW][MAX_COL];
	int sign = 1;
	
	if(Ncounter==1)
	{
		return det_arr[0][0];
	}
	
	for(int counter=0;counter<Ncounter;counter++)
	{
		Matrix::getCofactor(det_arr, temp_arr, 0, counter, Ncounter);
		Det+=sign*det_arr[0][counter]*Matrix::det(temp_arr,Ncounter-1);
		sign = -sign;
	}
	return Det;
}

float Matrix::Inverse(Matrix matrix)
{
	float DET=0.0;
	float ADJ[MAX_ROW][MAX_COL];
	
	
	if(matrix.row==matrix.col)
	{
		row=matrix.row;
		col=matrix.col;
		DET=Matrix::det(matrix.mat,row);
		
		if(DET!=0)
		{
			Matrix::adj(matrix.mat,ADJ);
			for(int counterout=0;counterout<row;counterout++)
			{
				for(int counterin=0;counterin<col;counterin++)
				{
					mat[counterout][counterin]=(1/DET)*ADJ[counterout][counterin];
				}
			}
		}
		else
		{
			cout<<"The determinant is 0 and the inverse can't be calculate!"<<endl;
		}
	
		
	}
	else
	{
		cout<<"The matrix is not quadratic!"<<endl;
	}
	return DET;
}
