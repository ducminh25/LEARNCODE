#include <bits/stdc++.h>
#define N 1000002
using namespace std;
int l,r,c[N];
void sangnt()
{
    c[0]=c[1]=1;
    for(int i=2;i*i<=N;i++)
        if(!c[i])
        for(int j=i*i;j<=N;j+=i)
        c[j]=1;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("cau1.inp","r",stdin);
    freopen("cau1.out","w",stdout);
    sangnt();
    cin>>l>>r;
    int dem=0;
    for(int i=l;i<r;i++)
    {
        if(!c[2*i+1])
        {
            dem++;
        }
    }
    cout<<dem;
    return 0;
}
