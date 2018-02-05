#include <iostream>

using namespace std;
long long mod(long long a,long long b)
{
    if(b==1)return a;
    long long s=mod(a,b/2)%10;
    if(b%2==0)return (s*s)%10;
    return (a*s*s)%10;
}

int main()
{
    int t,N;
    while(t--)
    {
        cin>>N;
        cout<<mod(N,N)<<endl;
    }
    return 0;
}
