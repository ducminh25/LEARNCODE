#include <bits/stdc++.h>
using namespace std;
int a[1005][1005], m, n;

void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
}

void sol() {
    int s1, s2, s;
    s1 = 0;
    for(int i = 1; i <= n; ++i)
        s1 += a[i][i];
    
    s2 = 0;
    for(int i = 1; i <= n; ++i) 
        s2 += a[i][n - i + 1];

    s = s1 + s2;
    if(n % 2 == 1) s -= a[n / 2 + 1][n / 2 + 1];

    cout << s;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    if(fopen("TONGCHEO.INP", "r")) {
        freopen("TONGCHEO.INP", "r", stdin);
        freopen("TONGCHEO.OUT", "w", stdout);
    }

    input();
    sol();
}