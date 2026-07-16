/* #include <bits/stdc++.h>
using namespace std;

long long N;
long long S (long long x) {
    long long sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen ("SOLVE.inp", "r", stdin);
    freopen ("SOLVE.out", "w", stdout);

    cin >> N;
    long long x = 1;
    while (x * x <= N) {
        long long sum = S(x);
        if (x * (x + sum) == N) {
            break;
        }
        x++;
    }

    if (x * x > N) {
        x = -1;
    }

    cout << x;

    return 0;
}
*/


#include <bits/stdc++.h>
using namespace std;

//giải phương trình, tìm ans
long long S (long long x) {
    long long sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main ()
{
    // x^2 + S (x)*x – N = 0. Find x min.
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // freopen ("SOLVE.inp", "r", stdin);
    // freopen ("SOLVE.out", "w", stdout);

    long long N, ans = INT_MAX;
    cin >> N;

    for (int i = 1; i <= 81; ++i)
    {
        long long delta = i * i + 4 * N;
        if (sqrt(delta) == (int)sqrt(delta))
        {
            long long x = -i + sqrt(delta);
            if (x % 2 == 0)
            {
                x /= 2;
                if (x * x + S (x) * x - N == 0) ans = min(ans,x);
            }
            
        }
    }
    if (ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}