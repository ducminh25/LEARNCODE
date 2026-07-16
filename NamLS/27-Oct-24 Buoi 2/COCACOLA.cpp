#include <bits/stdc++.h>
using namespace std;
int n, k;

void input() {
    cin >> n >> k;
}

void solve() {
    int cnt = n, temp = n;
    while (temp >= k) {
        int t = temp / k;
        cnt += t;
        temp = t + temp % k;
    }
    cout << cnt << endl;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    if(fopen("COCACOLA.INP", "r")) {
        freopen("COCACOLA.INP", "r", stdin);
        freopen("COCACOLA.OUT", "w", stdout);
    }
    
    input();
    solve();
    return 0;
}