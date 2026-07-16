#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000006],b[1000006],x,d=0,k=0,kq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        for(int j=2;j*j<=x;j++)
        {
            if(x%j==0)
            {
                b[j]++;
                while(x%j==0)
                {
                    x/=j;
                }
            }
        }
        if(x>1)
            b[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        kq=0;
        for(int j=2;j*j<=a[i];j++)
        {
            if(a[i]%j==0)
            {
                if(b[j]!=0)
                {
                        kq=1;
                        break;
                }
                while(a[i]%j==0)
                        a[i]/=j;
            }
        }
        if(a[i]>1)
        {
            if(b[a[i]]!=0)
                kq=1;
        }
        if(kq==0)
            k++;
    }
    cout<<k;
    return 0;
}
