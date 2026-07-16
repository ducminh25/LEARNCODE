#include <bits/stdc++.h>
using namespace std;

long long a_var, b_var;
long long large_array[150000000];

void input() {
    cin >> a_var >> b_var;
}

void solve() {
    for (int i = 0; i < 150000000; ++i) {
        large_array[i] = a_var + b_var;
    }
    cout << a_var + b_var << '\n';
}

int main() {
    ios_base :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
    input();
    solve();
    return 0;
}
