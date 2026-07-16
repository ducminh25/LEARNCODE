#include <bits/stdc++.h>
using namespace std;
#define io(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define ll long long
#define str string
#define mod 1000000007LL

ll n, m, k, check, ans = 0, a[1000005], b[1000005], snt[1000005], spf[1000005];
set<ll> st;
void sub1(){
    for(ll i = 1; i <= n; i++){
        check = 0;
        for(ll j = 1; j <= m; j++){
            if(__gcd(a[i], b[j]) != 1){
                check = 1;
                break;
            }
        }
        if(check == 0) ans++;
    }
    cout << ans;
}
void sub23(){
    for(ll i = 1; i <= m; i++){
        k = b[i];
        while(k > 1){
            st.insert(spf[k]);
            k /= spf[k];
        }
    }
    for(ll i = 1; i <= n; i++){
        k = a[i];
        check = 0;
        while(k > 1){
            if(st.find(spf[k]) != st.end()){
                check = 1;
                break;
            }
            k /= spf[k];
        }
        if(check == 0) ans++;
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    io("cau3");
    for(ll i = 1; i <= 1000000; i++) spf[i] = i;
    for(ll i = 2; i*i <= 1000000; i++){
        if(snt[i] == 0){
            for(ll j = i*i; j <= 1000000; j+=i){
                snt[j] = 1;
                spf[j] = i;
            }
        }
    }
    snt[0] = 1;
    snt[1] = 1;
    cin >> n >> m;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    for(ll i = 1; i <= m; i++) cin >> b[i];
    if(n <= 1000 && m <= 1000) sub1();
    else sub23();
    return 0;
}
