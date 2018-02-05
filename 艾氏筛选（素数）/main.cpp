#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std ;
const long long maxn=10000007+10;
const long long maxp=700000;
long long prime[maxp];
int s[maxn];
void sieve(long long n)
{
    long long m=(long long)sqrt(n+0.5);
    memset(s,0,sizeof(s));
    s[2]=0;
    for(long long i=3;i<=m;i+=2)
    {
        if(!s[i])
            for(long long j=i*i;j<=n;j+=i)
                s[j]=1;
        if(i*i>n)break;
    }
}
long long gen(long long n)
{
    sieve(n);
    long long c=1;
    prime[0]=2;
    for(long long i=3;i<=n;i+=2)
    {
        if(!s[i])prime[c++]=i;
    }
    return c;
}
int main()
{
    long long n,c;
    cout<<"number";
    cin>>n;
    c=gen(n);
    for(long long i=0;i<c;i++)
    {
        printf("%lld",prime[i]);
    }
    cout<<endl<<c;
    return 0;

}


