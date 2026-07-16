#include <bits/stdc++.h>
using namespace std;
const int MOD = 14062008;
int n, k;
vector<int> a;

void input() {
    cin >> n >> k;
    a.resize(k);
    for (int i = 0; i < k; ++i)
        cin >> a[i];
}

void sol() {
    vector<int> f(n + 1);
    f[1] = 1;

    for (int i = 2; i <= n; ++i) {
        if (find(a.begin(), a.end(), i) != a.end()) {
            f[i] = 0;
        } else {
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        }
    }

    cout << f[n] << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    sol();

    return 0;
}
