#include <bits/stdc++.h>
using namespace std;
int n, k, j ,res = 0, p [5000005];

void sieve ()
{
    for (int i = 1; i <= n; ++i) p [i] = i;
    for (int i = 2; i <= n/2 + 1; ++i)
    {
        if (p [i] == i)
        {
            j = i * 2;
            while (j <= n)
            {
                p [j] = i;
                j += i;
            }
        }
    }
}

void solve ()
{
    res = 0;
    for (int i = 2; i <= n; ++i)
    {
        if (p[i] <= k)
        {
            res++;
        }
    }
    cout << res;
}

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    cin >> n >> k;
    sieve ();
    solve ();
    return 0;
}