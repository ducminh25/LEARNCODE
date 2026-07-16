#include <bits/stdc++.h>

using namespace std;
int n,k;
string s;
map<string,int>mp;
bool kt(int mid)
{
    string s1="";
    mp.clear();
    for(int i=0;i<mid;i++)
    {
        s1+=s[i];
    }
    mp[s1]++;
    if(mp[s1]>=k)
        return true;
    for(int i=1;i<n-mid+1;i++)
    {
        s1.erase(0,1);
        s1+=s[i+mid-1];
        mp[s1]++;
        if(mp[s1]>=k)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);
    cin>>n>>k;
    cin>>s;
    int l=1,r=n,mid,res=-1;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(kt(mid))
        {
            res=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<res;
    return 0;
}
