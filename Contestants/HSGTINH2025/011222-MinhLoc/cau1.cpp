#include <bits/stdc++.h>
using namespace std;
#define io(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin); freopen(name".out","w",stdout);}
#define ll long long
#define str string
#define mod 1000000007LL

ll l, r, d = 0, snt[1000005];
void sub1(){
    for(ll i = l; i <= r; i++){
        for(ll j = i+1; j <= r; j++){
            if(snt[j*j-i*i] == 0) d++;
        }
    }
    cout << d;
}
void sub2(){
    for(ll i = l; i < r; i++){
        if(snt[i+i+1] == 0) d++;
    }
    cout << d;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    io("cau1");
    for(ll i = 2; i*i <= 1000000; i++) if(snt[i] == 0) for(ll j = i*i; j <= 1000000; j+=i) snt[j] = 1;
    snt[0] = 1;
    snt[1] = 1;
    cin >> l >> r;
    if(r <= 500) sub1();
    else sub2();
    return 0;
}
