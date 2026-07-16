#include<bits/stdc++.h>
using namespace std;
long long p[10000006];
void sanguoc()
{
    fill(p+1,p+1000000+1,1);
    for(int i=2;i*i<=1000000;i++)
        for(int j=i*i;j<=1000000;j+=i)
        {
            p[j]+=i;
            if(i*i!=j)
                p[j]+=j/i;
        }
}
long long n,a[1000006];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    if(fopen("TONGUOC.INP","r"))
    {
        freopen("TONGUOC.INP","r",stdin);
        freopen("TONGUOC.OUT","w",stdout);
    }
    sanguoc();
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cout<<p[a[i]]+a[i]<<' ';
    }
    return 0;
}
