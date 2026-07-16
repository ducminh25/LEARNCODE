#include<bits/stdc++.h>
using namespace std;
string s,a="",ans="";
long long cnt=0;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    if(fopen("XCLT.INP","r"))
    {
        freopen("XCLT.INP","r",stdin);
        freopen("XCLT.OUT","w",stdout);
    }
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=s[i-1]||i==0)
        {
            a+=s[i];
        }
        else
        {
            if(a.size()>cnt||a.size()==cnt&&a>ans)
            {
                cnt=a.size();
                ans=a;
            }
            a=s[i];
        }

    }
    if(a.size()>cnt||a.size()==cnt&&a>ans)
    {
        ans=a;
    }
    cout<<ans;
    return 0;
}
