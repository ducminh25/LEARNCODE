#include <bits/stdc++.h>
using namespace std;

#define N 10000001
int a[N];
int n, x;
bool find (int x, int a[], int l, int r) {
    while (l <= r) {
        int mid = l + (r - l) / 2; // lấy vị trí giữa đoạn [l, r] hoặc (l + r) / 2
        if (a[mid] == x) return true;
        else if (a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie (0); cout.tie (0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    cin >> x;

    if (find(x, a, 1, n - 1)) cout << "YES";
    else cout << "NO";

    return 0;
}