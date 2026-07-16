#include <bits/stdc++.h>
using namespace std;

long long a_var, b_var;

void input() {
    cin >> a_var >> b_var;
}

void solve() {
    long long zero_val = 0;
    long long result_val = (a_var + b_var) / zero_val;
    cout << result_val << '\n';
}

int main() {
    ios_base :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
    input();
    solve();
    return 0;
}
