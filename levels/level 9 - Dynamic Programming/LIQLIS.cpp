#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
const int maxn = 1e5 + 5;
int n, a[maxn], f[maxn], b[maxn], res = 0, maxx = 1;
const int maxt = 1e6 + 5;
int t[maxt], ds[maxt];

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
}

// Truy vết
void trace(int k) {
    int d = 0;
    while (k > 0) {
        d++;
        ds[d] = k;
        k = t[k];
    }

    for (int i = d; i >= 1; --i) {
        cout << ds[i] << " ";
    }
    cout << endl;
}

void solve() {
    int jmax, imax;
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= n; ++i) {
        jmax = 0;
        for (int j = 1; j <= i - 1; ++j) {
            if (a[j] < a[i] && f[j] > f[jmax]) jmax = j;
        }
        f[i] = f[jmax] + 1;
        t[i] = jmax;
    }
    imax = 1;
    for (int i = 2; i <= n; ++i) {
        if (f[i] > f[imax]) imax = i;
    }

    cout << f[imax] << endl;
    trace(imax);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    input();
    solve();

    return 0;
}


// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 1e5 + 5;
// int n, a[maxn], f[maxn], b[maxn], res = 0, maxx = 1;
// const int maxt = 1e6 + 5;
// int t[maxt], ds[maxt];

// void input() {
//     cin >> n;
//     for (int i = 1; i <= n; ++i) cin >> a[i];
// }

// void trace (int k) {
//     int d = 0;
//     while (k > 0) {
//         d++;
//         ds[d] = k;
//         k = t[k];
//     }

//     for (int i = d; i >= 1; --i) {
//         cout << ds[i] << ' ';
//     }
// }

// // Lower_bound() - 1: Tìm chỉ số của giá trị lớn nhất trong b[] nhỏ hơn x
// int binarySearch (int l, int r, int x) {
//     int mid, res = 0;
//     while (l <= r) {
//         mid = (l + r) / 2;
//         if (a[b[mid]] < x) {
//             res = mid;
//             l = mid + 1;
//         }
//         else r = mid - 1;
//     }

//     return b[res];
// }

// void sol() {
//     int res, jmax;
//     f[1] = 1; res = 1; b[1] = 1;
//     for (int i = 2; i <= n; ++i) {
//         jmax = binarySearch(1, f[res], a[i]);
//         f[i] = f[jmax] + 1;
//         t[i] = jmax;
//         b[f[i]] = i;
//         if(f[i] > f[res]) res = i;
//     }

//     cout << f[res] << '\n';
//     trace(res);
// }

// int main() {
//     ios_base :: sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     input();
//     sol();

//     return 0;
// }
