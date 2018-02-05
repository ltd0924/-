#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#define INF 0x7fffffff
using namespace std;
int Map[110][110],dis[110],vis[110];
int N,M;
void prime()
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=N;i++) dis[i]=Map[1][i];
    int sum=0;vis[1]=1;
    for(int p=1;p<=N-1;p++)
    {
        int t,Min=INF;
        for(int i=1;i<=N;i++)if(!vis[i]&&dis[i]<Min)
            Min=dis[i],t=i;
        sum+=Min;vis[t]=1;
        for(int i=1;i<=N;i++)if(!vis[i]&&dis[i]>Map[t][i])
            dis[i]=Map[t][i];
    }
    cout<<sum<<endl;
}
int main()
{
    while(cin>>N&&N)
    {
        for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) Map[i][j]=INF;
        M=(N-1)*N/2;
        int a,b,c;
        for(int i=0;i<M;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            Map[a][b]=Map[b][a]=c;
        }
        prime();
    }
    return 0;
}
