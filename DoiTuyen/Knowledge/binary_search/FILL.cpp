#include <bits/stdc++.h>
const int N = 1e5+2;
using namespace std;

struct reservoir {
    int b, h, w, d;
};

reservoir a[N];
int n, v;
double eps = 0.001;

bool check(double x) {
    double sum = 0;
    // Tính tổng các lượng nước ở các bể khi đạt độ cao x
    for(int i = 1; i <= n; ++i)
        if (a[i].b < x) 
            sum = sum + min((x-a[i].b), (double)a[i].h) * a[i].w * a[i].d;
    return sum >= v;
}

void solve() {
    double res;
    double first = 0, last = 1e6+4e4;
    while (first <= last) {
        double mid = (first + last)/2;
        if (check(mid)) {
            res = mid;
            last = mid - eps;
        }
        else first = mid + eps;
    }
    cout << fixed << setprecision(2) << res;
}

int main () {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    cin >> n >> v;
    for(int i = 1; i <= n; ++i)
        cin >> a[i].b >> a[i].h >> a[i].w >> a[i].d;
    solve();
    return 0;
}