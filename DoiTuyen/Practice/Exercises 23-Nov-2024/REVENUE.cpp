#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("REVENUE.inp", "r")) {
        freopen("REVENUE.inp", "r", stdin);
        freopen("REVENUE.out", "w", stdout);
    }

    int x, y, n;
    cin >> x >> y >> n;

    int revenue = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 7 == 1 || i % 7 == 0)
            revenue += y;
        else
            revenue += x;
    }

    cout << revenue;

    return 0;
}