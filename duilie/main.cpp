#include <cmath>
#include <cstdio>
#include <algorithm>
#define N 5002
using namespace std;

struct Q{
    int f,r,da[N];
    void init()
    {
        f=r=0;
    }
    void push(int a)
    {
        da[r++]=a;
    }
    int gettop()
    {
        return da[f++];
    }
    bool ch(){return r-f<4;}
    bool mpty(){return f==r;}

}q[2];
int main()
{
    int T,n,i;
    scanf("%d",&T);
    while(T--){
            scanf("%d",&n);
    q[0].init(),q[1].init();
    for(i=1;i<=n;i++){q[0].push(i);}
    int now=0,pre=1;
    i=0;dsbg
    while(!q[now].ch())
    {
        q[pre].init();
        if(i&1)
        {
           while(!q[now].mpty())
           {
               q[pre].push(q[now].gettop());
                if(q[now].mpty()){ break;}
                q[pre].push(q[now].gettop());
                if(q[now].mpty()) {break;}
                q[now].gettop();
           }
        }else
        {
            while(!q[now].mpty())
            {
                q[pre].push(q[now].gettop());
                if(q[now].mpty()){ break;}
                q[now].gettop();
            }
        }
        i^=1;
        swap(now,pre);
    }
    printf("%d",q[now].gettop());
    while(!q[now].mpty())
    {
        printf("%d",q[now].gettop());
    }
    puts("");
    }
}
