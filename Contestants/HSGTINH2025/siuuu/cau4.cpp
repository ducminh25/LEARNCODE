#include <bits/stdc++.h>
#define int long long
#define N 1000005
#define fi first
#define se second
using namespace std;
const int mod=1e9+2277;
const int mod1=2e9+11;
int base=131;
int base1=137;
int n,k,ans=1e9,f[N],t[N],f1[N],t1[N];
string s;
int get(int a,int b)
{
    return (f[b]-f[a-1]*t[(b-a+1)]%mod+mod)%mod;
}
int get1(int a,int b)
{
    return (f1[b]-f1[a-1]*t1[(b-a+1)]%mod1+mod1)%mod1;
}
bool check(int mid)
{//i->i+mid-1
    vector<pair<int,int>>v;
    for(int i=1;i<=n-mid+1;i++)
    {
        v.push_back({get(i,i+mid-1),get1(i,i+mid-1)});
    }
    sort(v.begin(),v.end());
//    for(int i=0;i<v.size();i++)
//    {
//        cout<<v[i].fi<<" "<<v[i].se<<'\n';
//    }
    int res=1;
     if(res>=k)return true;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].fi==v[i-1].fi&&v[i].se==v[i-1].se)
        {
            res++;
            if(res>=k)
            {
                return true;
            }
        }
        else
        {
            if(res>=k)return true;
            res=1;
        }
    }
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CAU4.inp","r",stdin);
    freopen("CAU4.out","w",stdout);
    cin>>n>>k;
    cin>>s;
    t[0]=1;
    t1[0]=1;
    for(int i=1; i<=n; i++)
    {
        t[i]=(t[i-1]*base)%mod;
        t1[i]=(t1[i-1]*base1)%mod1;
    }
    for(int i=0; i<n; i++)
    {
        f[i+1]=(f[i]*base+(s[i]-'a'+1))%mod;
        f1[i+1]=(f1[i]*base1+(s[i]-'a'+1))%mod1;
    }
    int l=1,r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            //cout<<mid<<" ";
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    if(ans==1e9)cout<<-1;
    else cout<<ans;
    return 0;
}
/*
DOC DE
TEN BAI
GIOI HAN DE BAI
KET QUA DAU RA
SINH TEST
THOI GIAN
*/
