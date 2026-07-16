#include <bits/stdc++.h>

using namespace std;
int n,k,demmax=-1;
string st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cau4.inp","r",stdin);
    freopen("cau4.out","w",stdout);
    cin>>n>>k;
    cin>>st;
    map<string,int>mp;
    for(int i=0;i<n;i++)
    {
        string t="";
        for(int j=i;j<n;j++)
        {
           t+=st[j];
           mp[t]++;
           if(mp[t]>=k)
           {
               cout<<t<<" ";
               demmax=max(demmax,(int)t.size());
           }
        }
    }
    cout<<demmax;
    return 0;
}
