#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define FOD(i,a,b) for(ll i=a;i<b;++i)
#define io(name) if(fopen(name".INP","r")){ freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define all(v) v.begin(),v.end()
#define ms(a,v) memset(a,v,sizeof(a));

stringstream ss;
ll n,k,res;
string s;
bool check(ll x)
{
    unordered_map<string,int> mp;
    string t = "";
    FOR(i,1,x) t += s[i];
    mp[t]++;
    FOR(i,x + 1,n){
        t.erase(0,1);
        t += s[i];
        mp[t]++;
        if(mp[t] >= k) return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("cau4")
    cin>>n>>k>>s;
    if(k == 1){
        cout<<n;
        return 0;
    }
    s = ' ' + s;
    ll l = 1, r = n;
    while(l <= r){
        ll mid = (l + r) / 2;
        if(check(mid)){
            res = max(res,mid);
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if(res == 0) cout<<-1;
    else cout<<res;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// #define FOR(i,a,b) for(ll i=a;i<=b;++i)
// #define FOD(i,a,b) for(ll i=a;i<b;++i)
// #define io(name) if(fopen(name".INP","r")){ freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
// #define all(v) v.begin(),v.end()
// #define ms(a,v) memset(a,v,sizeof(a));

// stringstream ss;
// ll n,k,res;
// string s;
// bool check(ll x)
// {
//     unordered_map<string,int> mp;
//     string t;
//     FOR(i,1,n - x + 1){
//         t = s.substr(i,x);
//         mp[t]++;
//         if(mp[t] >= k) return true;
//     }
//     return false;
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(nullptr);
//     cout.tie(nullptr);
//     io("cau4")
//     cin>>n>>k>>s;
//     if(k == 1){
//         cout<<n;
//         return 0;
//     }
//     s = ' ' + s;
//     ll l = 1, r = n;
//     while(l <= r){
//         ll mid = (l + r) / 2;
//         if(check(mid)){
//             res = max(res,mid);
//             l = mid + 1;
//         }
//         else r = mid - 1;
//     }
//     if(res == 0) cout<<-1;
//     else cout<<res;
//     return 0;
// }