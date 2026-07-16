#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N + 10],b[N + 10],m,n;
bool ok = true;
vector<bool> primes(N + 10,1);
void sang(){
    primes[0] = 0;
    primes[1] = 1;
    for(int i = 2; i * i <= N; i++){
        if(primes[i]){
            for(int j = i * i; j <= N; j += i) primes[j] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU3.INP","r",stdin);
    freopen("CAU3.OUT","w",stdout);
    sang();
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!primes[a[i]]) ok = false;
    }
    for(int i = 1; i <= m; i++){
        cin >> b[i];
        if(!primes[b[i]]) ok = false;
    }
    if(ok) cout << n;
    else if(n <= 1000 && m <= 1000){
        long long ans = 0;
        for(int i = 1; i <= n; i++){
            bool check = true;
            for(int j = 1; j <= m; j++){
                if(__gcd(a[i],b[j]) != 1){
                    check = false;
                    break;
                }
            }
            if(check) ans++;
        }
        cout << ans;
    }
    else{
        long long ans = 0;
        int k = b[1];
        for(int i = 2; i <= m; i++) k = __gcd(k,b[i]);
        if(k == 1){
            for(int i = 1; i <= n; i++){
                if(primes[a[i]]) ans++;
            }
            cout << ans;
        }
        else{
            for(int i = 1; i <= n; i++){
                if(a[i] % k != 0) ans++;
            }
            cout << ans;
        }
    }
    return 0;
}
