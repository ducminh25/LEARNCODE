#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, k;
int a[MAXN];
long long esum[MAXN], osum[MAXN];

void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        esum[i] = esum[i-1] + (a[i] % 2 == 0 ? a[i] : 0);
        osum[i] = osum[i-1] + (a[i] % 2 == 1 ? a[i] : 0);
    }

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if (fopen("DAYSODEP.inp", "r")) {
        freopen("DAYSODEP.inp", "r", stdin);
        freopen("DAYSODEP.out", "w", stdout);
    }

    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n;
        while (l <= r) {
            int mid = (l + r) / 2;
            long long ediff = esum[mid] - esum[i-1];
            long long odiff = osum[mid] - osum[i-1];
            
            if (ediff > 0 && odiff > 0 && 0 <= ediff - odiff && ediff - odiff <= k) {
                res += n - mid + 1;
                l = mid + 1;
            } 
            else if (ediff - odiff > k || (ediff == 0 && odiff == 0))
                r = mid - 1;
            else
                l = mid + 1;
        }
    }
    cout << res << endl;

    return 0;
}
