#include <bits/stdc++.h>
using namespace std;
long long f[45];
long long sum = 0;

void sol(int n) {
    f[1] = 1; f[2] = 1;
    for (int i = 3; i <= n; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    for (int i = 1; i <= n; ++i) {
        sum += f[i];
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BAI1.INP", "r")) {
        freopen("BAI1.INP", "r", stdin);
        freopen("BAI1.OUT", "w", stdout);
    }
    
    int n;
    cin >> n;
    sol(n);
    cout << sum << endl;
    
    return 0;
}