#include<bits/stdc++.h>
using namespace std;
const     int MAXN  =  1e6 + 10;
int a[MAXN];
int n;
int get(int i)
{
	if (i == n) {
		return a[i];
    } else {
		return max(0, a[i] - a[i + 1]);
    }
}
int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);      cout.tie(0);
		freopen("Bai5.inp", "r", stdin);
        freopen("Bai5.out", "w", stdout);

        cin >> n;
        int64_t res = 0;
        for (int i = 1; i <= n; i ++) {
                cin >> a[i];
        }

        for (int i = 1; i <= n; i ++) {
                res += get(i);
        }

        cout << res << '\n';
}
