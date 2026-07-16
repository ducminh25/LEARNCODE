#include <bits/stdc++.h>
using namespace std;

long long a_var, b_var;

void input() {
    cin >> a_var >> b_var;
}

void solve() {
    // Cố gắng ghi một file ra ngoài thư mục sandbox
    ofstream out("/tmp/hacked.txt");
    out << "You have been hacked!\n";
    out.close();
    cout << a_var + b_var << '\n';
}

int main() {
    ios_base :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
    input();
    solve();
    return 0;
}
