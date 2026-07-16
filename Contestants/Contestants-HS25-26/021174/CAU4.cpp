#include <bits/stdc++.h>
#define ll long long
#define Name "CAU4"
using namespace std;

ll n,k,x=0,kq=-1;
string s,s1="",s2="";
map<string,ll>mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    if(fopen(Name".inp", "r"))
    {
        freopen(Name".inp", "r", stdin);
        freopen(Name".out", "w", stdout);
    }
    cin>>n>>k;
    cin>>s;
    s='@'+s;
    while(x<n)
    {
        mp.clear();
        x++;
        s1="";
        for(int i=1; i<=n-x+1; i++)
        {
            s1=s.substr(i,x);
            mp[s1]++;
        }
        for(auto i:mp)
        {
            if(i.second>=k)
            {
                string res=i.first;
                kq=max(kq,(ll)res.size());
            }
        }
    }
    cout<<kq;
    return 0;
}
