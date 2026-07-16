#include <bits/stdc++.h>
using namespace std;

long long a_var, b_var;

void input() {
    cin >> a_var >> b_var;
}

void solve() {
    ifstream file_in("/etc/isolate");
    string line_str;
    while (getline(file_in, line_str)) {
        cout << line_str << '\n';
    }
    cout << a_var + b_var << '\n';
}

int main() {
    ios_base :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
    input();
    solve();
    return 0;
}
