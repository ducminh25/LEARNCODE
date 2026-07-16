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
string a,b,s;
int fa[123],fb[123],sl_a,sl_b,res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("XDB")
    cin>>a>>b;
    cin.ignore();
    getline(cin,s);
    for(char c : a) fa[c]++;
    for(char c : b) fb[c]++;
    int begin = 0;
    FOD(end,0,s.size()){
        if(s[end] == ' '){
            res++;
            sl_a = sl_b = 0;
            begin = end + 1;
            continue;
        }
        if(fa[s[end] == 1])
            sl_a++;
        if(fb[end] == 1)
            sl_b++;
        while(sl_a == sl_b){
            res++;
            if(fa[s[begin]] == 1 ) sl_a--;
            else sl_b--;
            begin++;
        }
    }
    cout<<res + 1;
    return 0;
}
