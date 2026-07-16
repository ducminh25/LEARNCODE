#include <bits/stdc++.h>
using namespace std;
#define io(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define ll long long
#define str string
#define mod 1000000007LL

ll n, k, ans = -1;
vector<char> res, res1;
str s;
void sub1(){
    for(ll i = 0; i < n; i++){
        for(ll j = i; j < n; j++){
            res.push_back(s[j]);
            ll d = 0;
            for(ll k = 0; k+j-i < n; k++){
                for(ll h = k; h <= k+j-i; h++) res1.push_back(s[h]);
                if(res == res1) d++;
                res1.clear();
            }
            if(d == k) ans = max(ans, j-i+1);
        }
        res.clear();
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    io("cau4");
    cin >> n >> k >> s;
    sub1();
    return 0;
}
