#include <bits/stdc++.h>
using namespace std;
#define io(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define ll long long
#define str string
#define mod 1000000007LL

ll n, k, a[1000005];
void sub1(){
    ll hmax = INT_MIN, ans = 0;
    for(ll i = 1; i <= n; i++) hmax = max(hmax, a[i]);
    for(ll i = 1; i <= n; i++) ans += hmax-a[i];
    cout << ans;
}
bool check(ll mid, ll hmax){
    ll d = 0;
    for(ll i = 1; i <= n; i++){
        if(hmax < a[i]){
            if(d == 1) return false;
            d++;
            hmax = mid;
            if(hmax < a[i]) return false;
        }
    }
    return true;
}
void sub2(){
    ll l = a[1], r = 1000000000, mid, t = 1000000000, hmax = a[1], ans = 0;
    while(l <= r){
        mid = (l+r)/2;
        if(check(mid, a[1])){
            t = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    for(ll i = 1; i <= n; i++){
        if(hmax >= a[i]) ans += hmax-a[i];
        else{
            hmax = t;
            ans += hmax-a[i];
        }
    }
    cout << ans;
}
void sub3(){
    ll ans = LLONG_MAX;
    for(ll i = 1; i <= n; i++){
        ll l = a[i], r = 1000000000, mid, t = 1000000000, hmax = a[i], sum = 0;
        while(l <= r){
            mid = (l+r)/2;
            if(check(mid, a[i])){
                t = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        for(ll j = 1; j <= n; j++){
            if(hmax >= a[j]) sum += hmax-a[j];
            else{
                hmax = t;
                sum += hmax-a[j];
            }
        }
        ans = min(ans, sum);
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    io("cau2");
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    if(k == 0) sub1();
    else if(k == -1) sub2();
    else sub3();
    return 0;
}
