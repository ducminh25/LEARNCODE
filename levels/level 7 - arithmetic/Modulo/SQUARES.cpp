#include <bits/stdc++.h>
using namespace std;
const int MOD = 2013;
int n;

int sol() {
    return n * (n + 1) * (2 * n + 1) / 6 % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    cin >> n;
    cout << sol();

    return 0;
}
