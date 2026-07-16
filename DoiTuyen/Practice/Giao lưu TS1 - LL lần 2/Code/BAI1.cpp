#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);    cout.tie(0);
	freopen("Bai1.INP","r",stdin);
    freopen("Bai1.OUT","w",stdout);	
    ll n;
    cin>>n;
    ll m,g=0,c=0;
    string s;
    cin>>s;
	m = s.size();
    for(int i=0;i<m;i++)
    {
        if(s[i]=='G')
			g++;
        if(s[i]=='C')
			c++;
    }
    ll ans=0,ind=1;
    for(int i=1;i<=n;i++)
    {
        ll x,g1=0,c1=0;
        string p;
        cin>>p;
		x = p.size();
        for(int j=0;j<x;j++)
        {
            if(p[j]=='G')
				g1++;
            if(p[j]=='C')
				c1++;
        }
        if(ans<g*c1+g1*c)
        {
            ans=g*c1+g1*c;
            ind=i;
        }
    }
    cout<<ind;  
	return 0;
}
   
    