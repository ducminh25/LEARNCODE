#include<bits/stdc++.h>
using namespace std;
long long t,n,k;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    if(fopen("TITEO.INP","r"))
    {
        freopen("TITEO.INP","r",stdin);
        freopen("TITEO.OUT","w",stdout);
    }
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
       cout<<k+(k-1)/(n-1)<<'\n';
    }
    return 0;
}
