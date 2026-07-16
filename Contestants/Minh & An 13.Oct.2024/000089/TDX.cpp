#include<bits/stdc++.h>
using namespace std;
long long q,n,m=0,d[30];
string a,b,s[15];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    if(fopen("TDX.INP","r"))
    {
        freopen("TDX.INP","r",stdin);
        freopen("TDX.OUT","w",stdout);
    }
    cin>>q;
    while(q--)
    {
        cin>>n;
        fill(d,d+28,0);
        for(int i=1;i<=n;i++)
            cin>>s[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<s[i].size();j++)
                d[s[i][j]-'a']++;
        }
        int f=0;
        for(int i=0;i<27;i++)
        {
            if(d[i]%n!=0)
                f=1;
        }
        if(f==0)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';

    }
    return 0;
}
