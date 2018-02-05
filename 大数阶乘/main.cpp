#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int i,j,m,l,k,n;
    int a[50000];
    memset(a,0,sizeof(a));
    a[0]=1;
    m=0;
    cin>>n;
    for(i=2;i<=n;i++)
    {
        for(j=0,l=0;j<=m;j++)
        {
            k=a[j];
            a[j]=(k*i+l)%10;
            l=(k*i+l)/10;
        }
        while(l)
        {
            a[++m]=l%10;
            l/=10;
        }
    }
    while(m>=0)cout<<a[m--];
    cout<<endl;
    return 0;
}
