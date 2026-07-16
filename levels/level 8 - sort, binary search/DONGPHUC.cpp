// ai – x <= bj <= ai + y
#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005], x, y;
int n, m;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int cnt = 0;
    int i = 1, j = 1;
    while (i <= n && j <= m) {
        if (a[i] - x > b[j])
            j++;
        else {
            if (a[i] + y < b[j])
                i++;
            else {
                cnt++;
                i++;
                j++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}

// O(n + m)