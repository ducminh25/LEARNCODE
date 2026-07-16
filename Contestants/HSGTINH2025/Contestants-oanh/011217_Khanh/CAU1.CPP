#include <bits/stdc++.h>
using namespace std;
long long c[1000006],l,r,x,d=0;
void snt()
{
    fill(c+1,c+1000006+1,1);
    for(int i=2;i*i<=1000006;i++)
        if(c[i]==1)
        for(int j=i*i;j<=1000006;j+=i)
        c[j]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);
    snt();
    cin>>l>>r;
    for(int i=l+1;i<=r;i++)
    {
        x=i*i-(i-1)*(i-1);
        if(c[x]==1)
            d++;
    }
    cout<<d;
    return 0;
}
