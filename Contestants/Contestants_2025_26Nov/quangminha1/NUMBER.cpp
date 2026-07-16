#include <bits/stdc++.h>
using namespace std;
long long f[1000005];
int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      freopen("NUMBER.inp","r",stdin);
      freopen("NUMBER.out","w",stdout);
long long q,n,i,j,dem=0;
string s;
cin>>q;
for(i=2;i<=20;i++)
{
    f[i]=i-1;
}
f[21]=12;
for(i=22;i<=30;i++)
{
    f[i]=f[21]+i-21;
}
f[31]=13;
f[41]=14;
f[51]=15;
f[61]=16;
f[71]=17;
f[81]=18;
f[91]=19;
for(i=32;i<=100;i++)
{
    if(f[i]==0)
    {
        f[i]=f[i/10*10+1]+i-(i/10*10+1);
    }
}
while(q--)
{
    cin>>n;
    cout<<f[n]<<'\n';
}
}


