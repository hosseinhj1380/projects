#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>

using namespace std;
struct info
{
  char fname[50];
  char lname[50];
  int idnumber;
  int nationalcode;
  int experience;
  int salary;
};
 int main()
{
  int n=40;
 info s[40];
   for (size_t i = 0; i <40; i++)
   {
     cout<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1<<"--"<<i+1;
     
     cout<<"\n";
     
     cout<<" first name: ";
    
     gets(s[i].fname);
    ////////////////////////////////////////////////////////////////////////
      cout<<"last name :";
    gets(s[i].lname);
  ////////////////////////////////////////////////////////////////////////
    cout<<"write personnely number "<<":";
     cin>>s[i].idnumber;
    ////////////////////////////////////////////////////////////////////////
    cout<<"write  national code "<<":";
    cin>>s[i].nationalcode;
    // ////////////////////////////////////////////////////////////////////////
     cout<<"write experience :";
     cin>>s[i].experience ; 
    // ////////////////////////////////////////////////////////////////////////
      cout<<"write salary by toman :" ;
    cin>>s[i].salary;
    fflush(stdin);
   }
   cout<<"---------------------------------------------------\n";
   system("cls");
   string tempt;
	string sortedname[n];
	for (int i = 0; i < n; i++)
	{
		sortedname[i] = s[i].lname;
	}
	
	for(int i=0;i< n;i++)
	{
	for(int j=i+1;j< n;j++)
	{
	if(sortedname[j]<sortedname[i])
	{
		tempt = sortedname[j];
		sortedname[j] = sortedname[i];
		sortedname[i]=tempt;
	}
	}
	} for (size_t i = 0; i < n; i++)
  {
     cout<<sortedname[i]<<endl;
  }
  
       cout<<"-------------------------------------------------\n";
       cout<<"under 3 million :\n";
       for (size_t i =1; i < 40; i++)

        {
           int a=s[i].salary;
          if (a<3000000)
          {
            cout<<s[i].fname<< " "<<s[i].lname<<endl;
          }
        }
        cout<<"---------------------------------------------------\n";
        cout<<"upper 10 years:\n";
        for (size_t i = 0; i < 40; i++)
        {
          int b=(s[i].experience);
          if (b>10)
          {
            cout<<s[i].fname<< " "<<s[i].lname<<endl;
          }

        }
        getch();
}
