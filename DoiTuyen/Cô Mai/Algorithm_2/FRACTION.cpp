#include <bits/stdc++.h>
using namespace std;

long long b, n, res;

int main () 
{
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    // freopen("FRACTION.inp", "r", stdin);
    // freopen("FRACTION.out", "w", stdout);

    cin >> b >> n;
 
    for (int m = 1; m <= n * 2; ++m) // Vòng lặp chạy từ 1 đến 2n
    {
        if ((b * m * (2 * n - m)) % (n * n) == 0)
        {   
            if (m != n && (b * m * (2 * n - m)) / (n * n) != b) 
                res ++;
        }
    }
 
    cout << res;
 
 return 0;
}