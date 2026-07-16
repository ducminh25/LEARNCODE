#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen ("TBC.inp", "r", stdin);
    // freopen ("TBC.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    map<long long, int> cnt;
    cnt[0] = 1;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        ans += cnt[sum - 1LL * (i + 1) * k];
        cnt[sum - 1LL * (i + 1) * k]++;
    }
    cout << ans << endl;
    return 0;
}