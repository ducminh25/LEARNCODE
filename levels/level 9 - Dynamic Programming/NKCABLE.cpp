#include <bits/stdc++.h>
using namespace std;
long long dis[25001], f[25001];
int n;

void input() {
    cin >> n;
    for (int i = 1; i <= n - 1; ++i) {
        cin >> dis[i];
    }
}

void sol() {
    f[1] = dis[1]; f[2] = dis[1];
    for (int i = 3; i <= n; ++i) {
        f[i] = min(f[i - 1], f[i - 2]) + dis[i - 1];
    }

    cout << f[n];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    sol();

    return 0;
}
