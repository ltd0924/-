#include <iostream>

using namespace std;

typedef long long ll;
ll p1(ll x,ll n)
{
    ll r=1,base=x;
    while(n)
    {
        if(n&1) r*=base;
        base*=base;
        n>>=1;
    }
    return r;
}
int main()
{

    ll x,n,s;
    cout<<"Ö¸Êı£º";
    cin>>n;
    cout<<"µ×Êı£º";
    cin>>x;
    s=p1(x,n);
    cout<<s;
    return 0;

}
