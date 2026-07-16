#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    vector<long long> a(n), b(m);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (long long i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long i = 0, j = 0, ans = 0;
    while (i < n && j < m) {
        if (a[i] > b[j]) {
            ans++;
            j++;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}
