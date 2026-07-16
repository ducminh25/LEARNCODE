#include <bits/stdc++.h>
#define N int(1e6)
using namespace std;
int n,m;
int a[N+6],b[N+6];
int d=0;
int p[N+6];
void pt(int n)
{
    int z=(int)sqrt(n);
    for(int i=2;i<=z;i++)
    {
        if(n%i==0)
        {
            p[i]=1;
            while(n%i==0)
            {
                n/=i;
            }
        }
        if(i>n)
            break;
    }
    if(n>1)
        p[n]=1;
}
void sub1()
{
    for(int i=1;i<=n;i++)
    {
        bool ok=true;
        for(int j=1;j<=m;j++)
        {
            if(__gcd(a[i],b[j])!=1)
            {
                ok=false;
                break;
            }
        }
        if(ok)
            d++;
    }
    cout<<d;
}
bool ck(int n)
{
    int z=(int)sqrt(n);
    for(int i=2;i<=z;i++)
    {
        if(n%i==0)
        {
            if(p[i]==1)
                return false;
            while(n%i==0)
            {
                n/=i;
            }
        }
        if(i>n)
            break;
    }
    if(n>1)
    {
        if(p[n]==1)
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    if(n<=1000&&m<=1000)
        sub1();
    else
    {
        for(int i=1;i<=m;i++)
            pt(b[i]);
        for(int i=1;i<=n;i++)
        {
            if(ck(a[i]))
                d++;
        }
        cout<<d;
    }
    return 0;
}
