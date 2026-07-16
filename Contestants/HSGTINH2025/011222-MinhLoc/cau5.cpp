#include <bits/stdc++.h>
using namespace std;
#define io(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define ll long long
#define str string
#define mod 1000000007LL

ll n, k, a[100005], mina1[100005], mina2[100005];
void sub1(){
    ll ans = INT_MIN;
    if(k == 1) for(ll i = 1; i <= n; i++) ans = min(ans, a[i]);
    else{
        mina1[1] = a[1];
        mina2[n] = a[n];
        for(ll i = 2; i <= n; i++) mina1[i] = min(mina1[i-1], a[i]);
        for(ll i = n-1; i >= 1; i--) mina2[i] = min(mina2[i+1], a[i]);
        for(ll i = 1; i < n; i++) ans = max(ans, mina1[i]+mina2[i+1]);
    }
    cout << ans;
}
bool check(ll mid){
    ll d = 0, j = 1;
    for(ll i = 1; i <= n; i++){
        if(i-j+1 == mid){
            d++;
            j=i+1;
        }
    }
    //cout << mid << ' ' << d << '\n';
    return d <= k;
}
void sub23(){
    ll l = 1, r = n, mid, ans = n, j = 1, t = 0, mina = INT_MAX;
    while(l <= r){
        mid = (l+r)/2;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
    for(ll i = 1; i <= n; i++){
        mina = min(mina, a[i]);
        if(i-j+1 == ans){
            j = i+1;
            cout << mina << '\n';
            if(n-j+1 >= k){
                t += mina;
                mina = INT_MAX;
            }
        }
    }
    cout << t;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    io("cau5");
    cin >> n >> k;
    for(ll i = 1; i <= n; i++) cin >> a[i];
    if(k <= 2) sub1();
    else sub23();
    return 0;
}
