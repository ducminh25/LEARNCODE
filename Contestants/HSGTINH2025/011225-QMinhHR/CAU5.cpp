#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
long long mi1[1000005],mi2[1000005];
int main()
{
    ios_base::sync_with_stdio();
    cin.tie();cout.tie();
    freopen("CAU5.inp","r",stdin);
    freopen("CAU5.out","w",stdout);
    long long n,k,i,dem=0,j,mi=LLONG_MAX,ma=LLONG_MIN;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==1)
    {
        for(i=1;i<=n;i++)
        {
            mi=min(mi,a[i]);
        }
        cout<<mi;
    }
    else
    {
        if(k==2)
        {
            mi1[0]=LLONG_MAX;
        mi2[n+1]=LLONG_MAX;
        for(i=1;i<=n;i++)
        {
            mi1[i]=min(mi1[i-1],a[i]);
        }
        for(i=n;i>=1;i--)
        {
            mi2[i]=min(mi2[i+1],a[i]);
        }
        for(i=1;i<=n-1;i++)
        {
            ma=max(ma,mi1[i]+mi2[i+1]);
        }
        cout<<ma;
        }
        else
        {
            sort(a+1,a+n+1);
            for(i=n;i>=n-k+1;i--)
            {
                dem=dem+a[i];
            }
            cout<<dem;
        }
    }
}
