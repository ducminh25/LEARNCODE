#include <bits/stdc++.h>
using namespace std;
int n, a, m;
long long w[100005];

long long fastPower(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a;
    
    long long temp = fastPower(a, n/2);
    if (n % 2 == 0)
        return temp * temp;
    else
        return temp * temp * a;
}

// void sol() {
//     int lt = 1;
//     long long res = 0;
//     for(int i = 1; i <= n; ++i) {
//         lt = ((lt % m) * (a % m)) % m;
//         w[i] = lt + 1;
//         res += w[i];
//     }

//     cout << res << "\n";
// }

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (NULL); cout.tie (NULL);
    
    cin >> n >> a >> m;
    long long sum = 0;
    for(int i = 1; i <= n; ++i) {
        w[i] = ((fastPower(a, i - 1) % m) * (a % m) % m) % m + 1;
        sum += w[i];
    }
    
    cout << sum << "\n";

    return 0;
}
