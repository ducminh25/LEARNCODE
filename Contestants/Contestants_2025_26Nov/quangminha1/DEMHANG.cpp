#include <bits/stdc++.h>
using namespace std;
unordered_map<long long,long long>d;
int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      freopen("DEMHANG.inp","r",stdin);
      freopen("DEMHANG.out","w",stdout);
long long n,i,x,kq1=0,kq2=0;
cin>>n;
for(i=1;i<=n;i++)
{
    cin>>x;
    d[x]++;
    if(d[x]>=kq2)
    {
        if(d[x]==kq2)
        {
            kq1=min(kq1,x);
        }
        else
        {
            kq1=x;
            kq2=d[x];
        }
    }
}
cout<<kq1<<" "<<kq2;
}
