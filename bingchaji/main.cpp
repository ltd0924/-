#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 30004

int n,r[N],fa[N],m[N];

void init()
{
    int i;
    for(i=0;i<N;i++)
    {
        fa[i]=i;m[i]=1;r[i]=0;
    }
}
int find(int x)
{
    int fx=fa[x];
    if(fa[x]!=x)
    {
        fx=find(fa[x]);
        r[x]+=r[fa[x]];
    }
    return fa[x]=fx;
}
void u(int x,int y)
{
    int fx=find(x),fy=find(y);
    fa[fy]=fx;
    r[fy]+=m[fx];
    m[fx]+=m[fy];
}
int main()
{
    char p[3];
    int i,j;
    while(scanf("%d",&n)!=-1)
    {
        init();
        while(n--)
        {
            scanf("%s",p);
            if(p[0]=='c')
            {
                scanf("%d",&i);
                int f=find(i);
                printf("%d",m[f]-r[i]-1);
            }
            else{
                scanf("%d%d",&i,&j);
                u(i,j);
            }
        }
    }
}
