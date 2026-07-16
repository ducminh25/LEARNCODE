#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define io(name) if(fopen(name".inp","r")){freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define FOR(i,a,b) for(ll i = a;i <= b;++i)
#define FOD(i,a,b) for(ll i = a;i < b;++i)
#define all(v) v.begin(),v.end()

ll t,n,cnt;
ll rev(ll x)
{
    stringstream ss;
    ss<<x;
    string s = ss.str();
    sort(all(s),greater<char>());
    ll ans = 0;
    for(char c : s) ans = ans * 10 + (c - '0');
    return ans;
}
ll solve(ll x)
{
    cnt = 0;
    if(x <= 20) return x - 1;
    ll t = 1;
    while(t < x){
        cnt++;
        t++;
        ll tmp = rev(t);
        if(tmp <= x && tmp > t){
            t = tmp;
            cnt++;
        }
        //cout<<t<<' ';
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("number")
    cin>>t;
    while(t--){
        cin>>n;
        cout<<solve(n)<<'\n';
    }
    return 0;
}
