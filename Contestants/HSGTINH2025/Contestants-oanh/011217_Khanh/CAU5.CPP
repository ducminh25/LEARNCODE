#include <bits/stdc++.h>
using namespace std;
long long n,k,a[1000006],ma=INT_MIN,mi1,mi2;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU5.INP","r",stdin);
    freopen("CAU5.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        mi1=*min_element(a+1,a+i+1);
        mi2=*min_element(a+i+1,a+n+1);
        ma=max(ma,mi1+mi2);
    }
    cout<<ma;
    return 0;
}
