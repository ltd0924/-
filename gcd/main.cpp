#include <iostream>
using namespace std;
int main()
{
    int gcd(int big, int small);
    int m,n;
    cin>>m,n;
    cout<<gcd(m,n)<<endl;
    return 0;
}
int gcd(int big,int small)
{
    if (small>big)swap(big,small);
    int temp;
    while(small!=0)
    {
        if(small>big)swap(big,small);
        temp=big%small;
        big=small;
        small=temp;
    }
    return(big);
}
