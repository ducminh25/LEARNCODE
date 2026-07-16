#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define FOD(i,a,b) for(ll i=a;i<b;++i)
#define io(name) if(fopen(name".INP","r")){ freopen(name".INP","r",stdin); freopen(name".OUT","w",stdout);}
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ms(a,v) memset(a,v,sizeof(a));

stringstream ss;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("XCLT")
    string s,tmp;
    vector<string> res;
    cin>>s;
    int n = s.size();
    s = '#' + s;
    FOR(i,1,n){
        if(s[i] != s[i - 1]) tmp += s[i];
        else{
            res.pb(tmp);
            tmp = s[i];
        }
        if(i == n) res.pb(tmp);
    }
    sort(res.begin(),res.end(),[](string a, string b){
        if(a.size() != b.size()) return a.size() > b.size();
        return a > b;
    });
    if(res.empty()) return cout<<"",0;
    cout<<res[0];
    return 0;
}