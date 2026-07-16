#include <bits/stdc++.h>
using namespace std;
int n, a[1000005];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    sort(a + 1, a + n + 1);
    long long temp1 = a[1] * a[2] * a[n];
    long long temp2 = a[n] * a[n - 2] * a[n - 1];
    cout << max(temp1, temp2);

    return 0;
}
