#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "interface.h"

using namespace std;

int main()
{
	int choice;
	float determinant;
	bool No_calculate=false;
	
	Matrix tableA;
	tableA.ReadMatrix('A');
	cout<<endl<<endl;
	
	Matrix tableB;
	tableB.ReadMatrix('B');
	
	Matrix result;
	
	system("CLS");
	
	do{
		
		cout<<"1 for Addition"<<endl;
		cout<<"2 for Subtraction"<<endl;
		cout<<"3 for Multiplication"<<endl;
		cout<<"4 for Inverse"<<endl;
		cout<<"5 for EXIT"<<endl;
		cout<<"choice: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				No_calculate=result.AddSubtract('+',tableA,tableB);
				if(!No_calculate)
					result.PrintMatrix();
				system("pause");
				break;
			case 2:
				No_calculate=result.AddSubtract('-',tableA,tableB);
				if(!No_calculate)
					result.PrintMatrix();
				system("pause");
				break;
			case 3:
				No_calculate=result.Multiply(tableA,tableB);
				if(!No_calculate)
					result.PrintMatrix();
				system("pause");
				break;
			case 4:
				cout<<"Inverse of A:"<<endl;
				determinant=result.Inverse(tableA);
				if(determinant!=0)
					result.PrintMatrix();
				cout<<endl<<endl;
				
				cout<<"Inverse of B:"<<endl;
				determinant=result.Inverse(tableB);
				if(determinant!=0)
					result.PrintMatrix();
				cout<<endl<<endl;
				system("pause");
				break;
			case 5:
				cout<<"Thanks for using this app!"<<endl;
				system("pause");
				break;
			default:
				cout<<"Wrong Input!"<<endl;
				system("pause");
				break;
		}
		
		system("CLS");
		
	}while(choice!=5);
	
	return 0;
}
