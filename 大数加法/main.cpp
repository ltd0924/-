#include <iostream>
#include <string>
#define N 10
using namespace std;

string plu(string num1,string num2)
{
   if(num1.size()<num2.size())
   {
       string temp=num1;
       num1=num2;
       num2=temp;
   }
   int length1=num1.size(),length2=num2.size(),flag=0,a,b,sum;
   while(length1>0)
   {
       a=num1[length1-1]-'0';
       if(length2>0) b=num2[length2-1]-'0';
       else b=0;
       sum=a+b+flag;
       if(sum>=N)
       {
           num1[length1-1]='0'+sum%N;
           flag=1;
       }else {num1[length1-1]='0'+sum; flag=0;}
       length1--;
       length2--;
   }
   if(flag==1) num1='1'+num1;
   return num1;
}
int main()
{
    string num1,num2,sum;
    cin>>num1>>num2;
    cout<<"num1"<<endl;
    cout<<"num2"<<endl;
    sum=plu(num1,num2);
    cout<<sum<<endl;
    return 0;
}
