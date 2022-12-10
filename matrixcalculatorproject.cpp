#include <iostream>
#include <cmath>
#include <conio.h>
//These lines defines arrows of the keyboard for the compiler to use
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
//------------------------------------------------------------------
using namespace std;

char ch,back;
void UI();

//These UIs shows what is happening during the oporations
void UI2() 
{
	system("cls");
	cout<<"\t Add Matrix Using Multi-dimensional Arrays\n\n";
}

void UI3()
{
	system("cls");
	cout<<"\t Multiple Two Matrix Using Multi-dimensional Arrays\n\n";
}

void UI4()
{
	system("cls");
	cout<<"\t Calculate Determinant of Matrix\n\n";
}

void UI5()
{
	system("cls");
	cout<<"\t Calculate ";
}
//-------------------------------------------------------------------------

//This is the function for calculating sum and minus of two matrixes
void sum() 
{
    jomp:
	char p;
	int r,c,s=1;
	double a[100][100],b[100][100];

	UI2();

	cout<<"Enter Number of Rows (Between 1 and 100): ";
	cin>>r;

	cout<<"Enter Number of Columns (Between 1 and 100): ";
	cin>>c;

	UI2();

	cout<<"\nEnter Elements of "<<s<<"nd Matrix\n";

	for(int i=0; i<r; i++) 
	{
		for(int j=0; j<c; j++) 
		{
			cout<<"Enter Element a"<<i+1<<j+1<<" : ";
			cin>>a[i][j];
		}
	}

	cout<<"\n   ";

	//This loop helps you to enter your oporation over and over again just like a pro calculator

	while(true) 
	{
		cout<<"Operation : ";
		cin>>p;

		UI2();

		switch(p) 
		{
			case '+': {
				++s;

				cout<<"\nEnter Elements of"<<s<<"nd Matrix\n";

				for(int i=0; i<r; i++)
				 {
					for(int j=0; j<c; j++) 
					{
						cout<<"Enter Element a"<<i+1<<j+1<<" : ";
						cin>>b[i][j];
						a[i][j]+=b[i][j];
					}
				}

				UI2();

				for(int i=0; i<r; i++)
				 {
					for(int j=0; j<c; j++)
					{
						cout<<a[i][j]<<" ";

						if(j==c-1)
							cout<<endl;
					}
				}

				cout<<endl;
				break;
			}

			case '-':
			 {
				++s;

				cout<<"\nEnter Elements of "<<s<<"nd Matrix\n";

				for(int i=0; i<r; i++)
				 {
					for(int j=0; j<c; j++) 
					{
						cout<<"Enter Element a"<<i+1<<j+1<<" : ";
						cin>>b[i][j];
						a[i][j]-=b[i][j];
					}
				}

				UI2();

				for(int i=0; i<r; i++) 
				{
					for(int j=0; j<c; j++) 
					{
						cout<<a[i][j]<<" ";

						if(j==c-1)
							cout<<endl;
					}
				}

				cout<<endl;
				break;
			}

			//This case will clear all of the calculated oporations and starts over the proggram

			case 'c': 
			{
				for(int i=0; i<r; i++) 
				{
					for(int j=0; j<c; j++) 
					{
						cout<<"\nEnter Element a"<<i+1<<j+1<<" : ";
						a[i][j]=0;
					}
				}

				goto jomp;
				break;
			}

			case 'E':
				exit(0);
				break;

			default :
				cout<<"Wrong oporation...!\n";
		}
	}
}
  //----------------------------------------------------------------

//This function is used for multipicaton of two matrixes
void mult() 
{
	UI3();

	int r1,r2,c1,c2;
	double mult[100][100];

	cout<<"TIP:First Matrix Column & Second Matrix Row Should Be Same.\n\n";
	cout<<"(First Matrix)\n";

	cout<<"Enter Number of Rows (Between 1 and 100): ";
	cin>>r1;

	cout<<"Enter Number of Columns (Between 1 and 100): ";
	cin>>c1;

	double a[r1][c1];

	cout<<endl;

	cout<<"(Second Matrix)\n";
	cout<<"Enter Number of Rows (Between 1 and 100): ";
	cin>>r2;

	cout<<"Enter Number of Columns (Between 1 and 100): ";
	cin>>c2;

	double b[r2][c2];
	UI3();

	//store matrices ------------------------------------------------------------------

	cout<<"\nEnter Elements of First Matrix:\n";

	for(int i=0; i<r1; i++) 
	{
		for(int j=0; j<c1; j++) 
		{
			cout<<"Enter Element a"<<i+1<<j+1<<" : ";
			cin>>a[i][j];
		}
	}

	cout<<"\nEnter Elements of Second Matrix:\n";
	for(int i=0; i<r2; i++) 
	{
		for(int j=0; j<c2; j++) 
		{
			cout<<"Enter Element a"<<i+1<<j+1<<" : ";
			cin>>b[i][j];
		}
	}

	//Multipication----------------------------------------------------------------------

	for(int i=0; i<r1; i++) 
	{
		for(int j=0; j<c2; j++) 
		{
			for(int k=0; k<c1; k++)
				mult[i][j] +=a [i][k] * b[k][j];
		}
	}

	UI3();

	//Displaying ------------------------------------------------------------------

	cout<<"Multiple of Matrix is:\n";

	for(int i=0; i<r1; i++) 
	{
		for(int j=0; j<c2; j++) 
		{
			cout<<mult[i][j]<<" ";
			if(j==c2-1)
				cout<<endl;

			mult[i][j]=0;
		}
	}

	cout<<"\nDo you want to try another thing? (y or n): ";
	cin>>ch;

	if(ch=='y') UI();
	else if(ch=='n') exit(0);
}
//------------------------------------------------------------------



//This part is for calculating determinant of A matrix


double det2(int n,double mat[][100]) 
{
	// determinant -------------------------------------------------------------------

	double submat[100][100];
	int subi,subj;
	double det=0;

	if(n==1)
		det=mat[0][0];
	else if(n==2)
		det=((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
	else {
		for(int c=0; c<n; c++) 
		{
			subi=0;
			for(int i=1; i<n; i++) 
			{
				subj=0;
				for(int j=0; j<n; j++) 
				{
					if(j==c) continue;
					submat[subi][subj]=mat[i][j];
					subj++;
				}
				subi++;
			}
			det+=(pow(-1,c) * mat[0][c] * det2(n-1,submat));
		}
	}
	return det;
	det=0;
}

void det1() 
{
	int n;
	double mat[100][100];

	UI4();

	cout<<"Enter The Order of Matrix: ";
	cin>>n;

	UI4();

	// store elements-----------------------------------------------------------------

	cout<<"Enter Element of Matrix.\n";
	for(int i=0; i<n; i++) 
	{
		for(int j=0; j<n; j++) 
		{
			cout<<"Enter Element a"<<i+1<<j+1<<" : ";
			cin>>mat[i][j];
		}
	}

	UI4();

	// displaying -----------------------------------------------

	cout<<"\nDeterminant = "<<det2(n,mat);
	cout<<"\nDo you wanna Try Another One? (y or n): ";
	cin>>ch;

	if(ch=='y') UI();
	else if(ch=='n') exit(0);
}
  //-----------------------------------------------------------------------------


  //These are the function for calculating inverse of a matrix
  
  
int store(float a[100][100])
{
	int n;
	
	system("cls");
	
	cout<<"\n Enter Length Of Matrix N*N : ";
	cin>>n;
	
	cout<<"\n--------------------------\n";
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cout<<" Matrix["<<i+1<<"]["<<j+1<<"] : ";
			cin>>a[i][j];
		}
	cout<<"\n----------------------------------------------------\n";
	
return n;
}

void Show(float a[100][100],int n,int show)
{
	if(show == 1)
		for(int i=0;i < n;i++)
		{
			for(int j=0;j < n;j++)
				cout<<" "<<a[i][j]<<" \t";
			cout<<"\n";
		}
	else if(show == 2)
	{
		cout<<"\n\n The Inverse Of Matrix Is : \n\n";
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++)
				cout<<" "<<a[i][j]<<" \t";
			cout<<"\n";
		}
	}
}

//	calculate minor of matrix
void minor(float b[100][100],float a[100][100],int i,int n)
{
	int h=0,k=0;
	for(int l=1;l<n;l++)
		for(int j=0;j<n;j++){
			if(j == i)
				continue;
			b[h][k] = a[l][j];
			k++;
			if(k == (n-1)){
				h++;
				k=0;
			}
		}
}

  //calculate determinte of matrix
float det(float a[100][100],int n)
{
	float b[100][100],sum=0;
	if (n == 1)
return a[0][0];
	else if(n == 2)
return (a[0][0]*a[1][1]-a[0][1]*a[1][0]);
	else
		for(int i=0;i<n;i++)
		{
			minor(b,a,i,n);
			sum = (float) (sum+a[0][i]*pow(-1,i)*det(b,(n-1)));
		}
return sum;
}

   //calculate transpose of matrix
void transpose(float c[100][100],float d[100][100],int n,float det)
{
	float b[100][100];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			b[i][j] = c[j][i];
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			d[i][j] = b[i][j]/det;
}

  //calculate cofactor of matrix
void cofactor(float a[100][100],float d[100][100],int n,float determinte)
{
	float b[100][100],c[100][100];
	int h,m,k;
	for (int h=0;h<n;h++)
		for (int l=0;l<n;l++){
			m=0;
			k=0;
			for (int i=0;i<n;i++)
				for (int j=0;j<n;j++)
					if (i != h && j != l){
						b[m][k]=a[i][j];
						if (k<(n-2))
							k++;
						else{
							k=0;
							m++;
						}
					}
			c[h][l] = (float) pow(-1,(h+l))*det(b,(n-1));
		}
	transpose(c,d,n,determinte);
}

//	calculate inverse of matrix
void inverse(float a[100][100],float d[100][100],int n,float det)
{
	if(det == 0)
		cout<<"\nInverse of Entered Matrix is not possible\n";
	else if(n == 1)
		d[0][0] = 1;
	else
		cofactor(a,d,n,det);
}

void Inverse()
{
	int n;
	float a[100][100],d[100][100],deter; 
	
	n = store(a);
	
	int print_matrix = 1;
	
	Show(a,n,print_matrix);	
	
	deter = (float) det(a,n);
		
		cout<<"----------------------------------------------------\n";
		cout<<"\n\n Determinant of the Matrix : "<<deter;
		cout<<"\n\n-----------------------\n";
		
	inverse(a,d,n,deter);
	
	int print_inverse = 2;
	
	Show(d,n,print_inverse);
     
    cout<<"\nDo you waqnt to try another thing? (y or n)";
    cin>>ch;
    
    if(ch=='y')
       UI();
    else if(ch=='n')
       exit(0);
}
  //--------------------------------------------------------------------------


  //This is the UI function
void UI() 
{
	system("cls");
	cout<<"\n\n                              MATRIX  CALCULATOR\n\n\n";
	cout<<"----------------------------------------------------------------------------\n\n";
	cout<<"                           [ Sum & Minus Of Matrix ]          \n\n";
	cout<<"                                       *                      \n";
	cout<<"                                       *                      \n";
	cout<<"                                    * * * *                   \n";
	cout<<"   [ Determinant Of Matrix ] * * *  * * * *  * * * [ Multiple Of Matrix ]\n";
	cout<<"                                    * * * *                   \n";
	cout<<"                                       *                      \n";
	cout<<"                                       *                      \n\n";
	cout<<"                             [ Inverse Of Matrix ]               \n\n";
	cout<<"------------------------------------------------------------------------------\n\n";

	int o=0;
	while(true) {
		o=0;
		switch((o=getch())) 
		{
			case KEY_UP:
				sum();
				break;
			case KEY_DOWN:
				Inverse();
				break;
			case KEY_LEFT:
				det1();
				break;
			case KEY_RIGHT:
				mult();
				break;
			default :
				UI();
		}
	}
}
//------------------------------------------------------------


int main() 
{
	UI();
	getch();
}