#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 50004
int s[N],n;
int lb(int k)
{
    return k&-k;
}
void add(int k,int v)
{
    while(k<=n)
    {
        s[k]+=v;
        k+=lb(k);
    }
}
int sum(int k)
{
    int re=0;
    while(k>0)
    {
        re+=s[k];
        k-=lb(k);
    }
    return re;
}
int main()
{
    char p[5];
    int T,ca=1,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(s,0,sizeof(s));
        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            add(i,j);
        }
        printf("case%d:\n",ca++);
        while(scanf("%s",p)&&p[0]!='e')
        {
            scanf("%d%d",&i,&j);
            if(p[0]=='q') {printf("%d\n",sum(j)-sum(i-1));}
                else {
                        if(p[0]=='a')
                        {add(i,j);}
                else {add(i,-j);}
                }

        }
    }
}
