#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if (fopen ("BAI3.INP", "r")) {
        freopen ("BAI3.INP", "r", stdin);
        freopen ("BAI3.OUT", "w", stdout);
    }

    int n, S;
    cin >> n >> S;

    int x, y;
    cin >> x >> y;

    vector<int> xs(n);
    for (int i = 0; i < n; i++) {
        cin >> xs[i];
    }

    sort(xs.begin(), xs.end());

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            // cout << abs(xs[mid] - xs[i]) * 1LL * abs(y) << endl;
            if (abs(xs[mid] - xs[i]) * 1LL * abs(y) > 2 * S) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        ans += n - l;
    }

    cout << ans << endl;

    return 0;
}