#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;

long long a_var, b_var;

void input() {
    cin >> a_var >> b_var;
}

void solve() {
    // Ngủ 10 giây để test Wall Time vs CPU Time
    std::this_thread::sleep_for(std::chrono::seconds(10));
    cout << a_var + b_var << '\n';
}

int main() {
    ios_base :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
    input();
    solve();
    return 0;
}
