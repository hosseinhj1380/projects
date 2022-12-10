#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <cstring>
using namespace std;
struct cellphone
{
    
  string cellphonebrand;

  int nationalcode;
  int  cellphoneid;
  int registrationfee;
};
int main (){
    int num,sum;
    cout<<"please write number of phone :\n";
    cin>>num;
    cellphone s[num];
    cout<<"national code :\n";
    cin>>s[0].nationalcode;

    int id=1001;
    for (size_t i = 0; i < num; i++)
    { 

       cout<<"enter brand :";
       cin>>s[i].cellphonebrand;

       if (s[i].cellphonebrand=="apple")
       {
           s[i].cellphoneid=id;
           s[i].registrationfee=1000;
           id++;

       }else if (s[i].cellphonebrand=="samsung")
       {
          s[i].cellphoneid=id;
           s[i].registrationfee=900;
           id++;
       }else if (s[i].cellphonebrand=="htc")
       {
           s[i].cellphoneid=id;
           s[i].registrationfee=800;
           id++;
       }else if  (s[i].cellphonebrand=="huawei")
       {
           s[i].cellphoneid=id;
           s[i].registrationfee=700;
           id++;
       }else {
           cout<<"wrong input !";
           exit(0);
       }
   }
        
       for (size_t i = 0; i < num; i++)
       {
           cout<<s[i].cellphoneid<<" "<<s[i].cellphonebrand<<" "<<s[i].registrationfee<<endl;
            sum+=s[i].registrationfee;
       }cout<<sum;


       
}