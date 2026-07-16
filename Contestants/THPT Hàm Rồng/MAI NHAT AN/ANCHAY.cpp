#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    if(fopen("ANCHAY.INP","r"))
    {
        freopen("ANCHAY.INP","r",stdin);
        freopen("ANCHAY.OUT","w",stdout);
    }
    cin>>n>>m;
    m--;
    long long sotuan= m/7;
    long long sodu=m%7;
    long long tong=sotuan*2;
    for(int i=n;i<=n+sodu;i++)
    {
        if(i==7||i==8||i==14||i==15)
            tong++;
    }
    cout<<tong;
    return 0;
}
