#include <bits/stdc++.h>
using namespace std;
int n, k;

int f(int n, int k) {
    if ((n - k) % 2 == 1 || n < k + 2) return 1;
    int t1 = f((n - k) / 2, k) + f((n + k) / 2, k);
    // cout << t1;
    return t1;
}

void solve() {
    cin >> n >> k;
    int s = f(n, k);
    cout << s;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if(fopen("RAFT.inp", "r")) {
        freopen("RAFT.inp", "r", stdin);
        freopen("RAFT.out", "w", stdout);
    }

    solve();
    return 0;
}