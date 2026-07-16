#include <bits/stdc++.h>

using namespace std;
int n,k;
string s;
int res=-1;
bool ck(int mid)
{
    map<string,int>mp;
    string s1=s.substr(0,mid);
    mp[s1]++;
    if(mp[s1]==k)
        return true;
    for(int i=1;i<n;i++)
    {
        string s1=s.substr(i,mid);
        mp[s1]++;
         if(mp[s1]==k)
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);
    cin>>n>>k;
    cin>>s;
   int l=1,r=n;
   while(l<=r)
   {
       int mid=(r+l)/2;
       if(ck(mid))
       {
           res=mid;
           l=mid+1;
       }
       else
        r=mid-1;
   }
   cout<<res;
    return 0;
}
