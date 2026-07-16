#include <bits/stdc++.h>
using namespace std;

long long a_var, b_var;

void input() {
    cin >> a_var >> b_var;
}

void solve() {
    // In ra các ký tự rác, ký tự null để xem checker có bị crash / tràn bộ đệm không
    for(int i = 0; i < 10000; ++i) {
        cout << '\0' << '\x07' << (char)255;
    }
    cout << '\n';
}

int main() {
    ios_base :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
    input();
    solve();
    return 0;
}
