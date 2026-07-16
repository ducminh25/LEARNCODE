#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

ll n, d = 0, d0 = 0, d1 = 0, t = 0;
str s;
void sub1(){
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j < n; j++){
            for(ll k = j+1; k < n; k++){
                if(s[i] == 'C' && s[j] == 'O' && s[k] == 'W'){
                    //cout << i << ' ' << j << ' ' << k << '\n';
                    d++;
                }
            }
        }
    }
    cout << d;
}
void sub2(){
    for(ll i = 0; i < n; i++){
        if(s[i] == 'C'){
            if(d1 != 0){
                t += d0*d1;
                d0 = 1;
                d1 = 0;
            }
            else d0++;
        }
        else if(s[i] == 'O') d1++;
        else{
            d += t+d0*d1;
        }

    }
    cout << d;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("COW.INP", "r", stdin);
    freopen("COW.OUT", "w", stdout);
    cin >> n >> s;
    //sub2();
    if(n < 255) sub1();
    else sub2();
    return 0;
}
