#include <bits/stdc++.h>
using namespace std;
long long n, a[100005], res[100005];

long long factor(int n)
{
    int i = 2;
    int cnt = 0;
    int sq = sqrt(n);
    while (i <= sq) {
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        i++;
    }
    if (n > 1)
        cnt++;

    return cnt;
}

void sol() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long s = 0, maxx = 0;
    for (int i = 0; i < n; ++i) {
        res[i] = factor(a[i]);
        s += res[i];
        maxx = max(maxx, res[i]);
    }

    cout << s - maxx << endl;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    sol();
    return 0;
}