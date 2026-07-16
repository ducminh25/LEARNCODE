#include <bits/stdc++.h>
using namespace std;
long long d1[1000005],d2[1000005];
int main()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
      freopen("COW.inp","r",stdin);
      freopen("COW.out","w",stdout);
long long n,i,dem=0,j,k;
string s;
cin>>n;
cin>>s;
s="#"+s;
if(n<255)
{
    for(i=1;i<=n-2;i++)
{
    for(j=i+1;j<=n-1;j++)
    {
        for(k=j+1;k<=n;k++)
        {
            if(s[i]=='C'&&s[j]=='O'&&s[k]=='W')
            {
                dem++;
            }
        }
    }
}
cout<<dem;
}
else
{
    for(i=n;i>=1;i--)
{
    d2[i]=d2[i+1];
    if(s[i]=='W')
    {
        d2[i]++;
    }
}
for(i=1;i<=n;i++)
{
    d1[i]=d1[i-1];
    if(s[i]=='C')
    {
        d1[i]++;
    }
}
dem=0;
for(i=2;i<=n-1;i++)
{
    if(s[i]=='O')
    {
        dem=dem+d1[i-1]*d2[i+1];
    }
}
cout<<dem;
}

}
