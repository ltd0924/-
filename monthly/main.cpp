#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int n,m;
int a[100002];
bool find(int top)
{
    int num=1;
    int cur=0;
    for(int i=0;i<n;i++)
    {
        if(cur+a[i]<=top)cur+=a[i];
        else
        {
            num++;
            cur=a[i];
        }
    }
    return(num<=m);
}
int main()
{
    while(cin>>n>>m&&n)
    {
        int sum=0;
        int ma=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
            ma=max(ma,a[i]);
        }
        int low=ma,high=sum,mid;
        while(low!=high)
        {
            mid=(low+high)>>1;
            if(find(mid))high=mid;
            else low=mid+1;
        }
        printf("%d\n",low);
    }
    return 0;
}
