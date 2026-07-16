#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < N - 1; ++i) {
        int d = a[i + 1] - a[i] - 1;
        if (d > 0) {
            int c = min(d, K);
            K -= c;
            ans += c;
        }
    }

    if (K > 0) {
        ans += K;
    }

    ans += N;

    cout << ans << endl;

    return 0;
}