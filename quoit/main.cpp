#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#define MAX 1e10
using namespace std;

int a,b;
struct Node
{
    double x,y;
    int key;
}ar[100005],br[100005];
bool cmpx(Node a,Node b)
{
    return a.x<b.x;
}
bool cmpy(Node a,Node b)
{
    return a.y<b.y;
}
double Min(double a,double b)
{
    return a<b?a:b;
}
double dis(Node a,Node b)
{
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}
double cal(int s,int e)
{
    int mid,i,j,tail=0;
    double d;
    if(s==e)return MAX;
    mid=(s+e)/2;
    d=Min(cal(s,mid),cal(mid+1,e));
    for(i=mid;i>=s&&ar[mid].x-ar[i].x<d;i--)
    {
        br[tail++]=ar[i];
    }
    for(i=mid+1;i<e&&ar[i].x-ar[mid].x<d;i++)
    {
        br[tail++]=ar[i];
    }
    sort(br,br+tail,cmpy);
    for(i=0;i<tail;i++)
    {
        for(j=i+1;j<tail&&br[j].y-br[i].y<d;j++)
        {
            if(d>dis(br[i],br[j]))
            {
                a=Min(br[i].key,br[j].key);
                b=br[i].key+br[j].key-a;
                d=Min(d,dis(br[i],br[j]));
            }
            printf("%lf\n",d);
        }
    }
    return d;
}
int main()
{
    int n;
    while(cin>>n&&n)
    {
        for(int i=0;i<n;i++)
        {
            ar[i].key=i+1;
            scanf("%lf%lf",&ar[i].x,&ar[i].y);
        }
        sort(ar,ar+n,cmpx);
        double d=cal(0,n);
        printf("%.2lf\n",d/2.0);
    }
    return 0;
}
