#include <bits/stdc++.h>
#define N int(1e6)
using namespace std;
int l,r;
int p[N+5];
long long d=0;
void sang()
{
    for(int i=2;i<=N;i++)
        p[i]=1;
    p[0]=p[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(p[i]==1)
            for(int j=i*i;j<=N;j+=i)
                p[j]=0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);
    sang();
    cin>>l>>r;
    for(int i=l+1;i<=r;i++)
    {
        if(p[i-1+i]==1)
            d++;
    }
    cout<<d;
    return 0;
}
