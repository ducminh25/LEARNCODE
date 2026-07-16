#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int L,R;
long long ans = 0;
vector<bool> primes(N + 10,1);
void sang(){
    primes[0] = primes[1] = 0;
    for(int i = 2; i * i <= N; i++){
        if(primes[i]){
            for(int j = i * i; j <= N; j += i) primes[j] = 0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("CAU1.INP","r",stdin);
    freopen("CAU1.OUT","w",stdout);
    sang();
    cin >> L >> R;
    for(int i = L; i < R; i++){
        if(primes[2*i + 1]) ans++;
    }
    cout << ans;
    return 0;
}
