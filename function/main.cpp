#include <iostream>
#include <cmath>
#include <stdio.h>
#include <iomanip>
using namespace std;
double a1,b1,c1,a2,b2,c2;
double f(double e)
{
    return max(a1*e*e+b1*e+c1,a2*e*e+b2*e+c2);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a1>>b1>>c1>>a2>>b2>>c2;
        double left=0,right=1000;
        while(right-left>=1e-8)
        {
            double mid1=left+(right-left)/3,mid2=right-(right-left)/3;
            if(f(mid1)<f(mid2)+1e-8)right=mid2;
            else left=mid1;
        }
    cout <<fixed<<setprecision(4)<<f(left)<< endl;
    }
    return 0;
}
