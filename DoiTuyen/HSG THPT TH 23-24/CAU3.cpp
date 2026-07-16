#include <bits/stdc++.h>
using namespace std;
const int maxn = 2250005;
int n;
long long sum = 0, minn = LLONG_MAX;
vector<int> a;

void input() {
    cin >> n;
    int tmp = n * n;
    a.resize(tmp);
    for (int i = 0; i < tmp; i++) {
        cin >> a[i];
        sum += a[i];
    }
}

void solve() {
    sort(a.begin(), a.end());
    int tmp = n * n;
    int cnt = 1;
    for (int i = 1; i < tmp; ++i) {
        if (a[i] == a[i - 1]) cnt++;
        else {
            minn = min(minn, (long long) cnt * a[i - 1]);
            cnt = 1;
        }
    }
    minn = min(minn, (long long) cnt * a.back());
    cout << sum - minn << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU3.inp", "r")) {
        freopen("CAU3.inp", "r", stdin);
        freopen("CAU3.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
