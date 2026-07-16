#include <bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
ll i,j=1,i_max,j_max,res=0;
str s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("XCLT.inp","r",stdin);
    freopen("XCLT.out","w",stdout);
    cin>>s;
    s=(char)(s[0])+s+(char)(s[s.size()-1]);
    for(i=1;i<s.size();i++)
        if(s[i]!=s[i-1])
            j++;
    else
    {
        if(j>res)
        {
            i_max=i-j;
            j_max=j;
            res=j;
        }
        j=1;
    }

    cout<<s.substr(i_max,j_max);
}
