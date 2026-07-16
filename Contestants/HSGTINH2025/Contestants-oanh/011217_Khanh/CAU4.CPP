#include <bits/stdc++.h>
using namespace std;
string s,st;
int k,ma=-1,n;
map<string,int>v;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);
    cin>>n>>k;
    cin>>s;
    int x=1;
    while(x<s.size())
    {
        v.clear();
        for(int i=0;i<s.size()-x+1;i++)
        {
            st=s.substr(i,x);
            v[st]++;
            if(v[st]==k)
            {
                ma=max(ma,x);
                break;
            }
        }
        x++;
    }
    cout<<ma;
    return 0;
}
