#include <bits/stdc++.h>
#define N int(2e5)
using namespace std;
int l,r;
long long d=0;
bool nt(long long n)
{
    if(n<2)
        return false;
    if(n<=3)
        return true;
    if(n%2==0||n%3==0)
        return false;
    for(int i=5;1LL*i*i<=n;i+=6)
        if(n%i==0||n%(i+2)==0)
        return false;
    return true;
}
void sub1()
{
     for(int i=l;i<r;i++)
    {
        for(int j=i+1;j<=r;j+=2)
        {
            long long t2=1LL*j*j, t1=1LL*i*i;
            if(nt(t2-t1))
            {
               d++;
            }
        }
    }
    cout<<d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);
    cin>>l>>r;
    if(r<=2000)
        sub1();
    else
    {
        d=0;
        for(int i=l+1;i<=r;i++)
        {
            int j=i-1;
            long long t1=1LL*j*j,t2=1LL*i*i;
            if(nt(t2-t1))
                d++;
        }
        cout<<d;
    }
    return 0;
}
