#include <bits/stdc++.h>
using namespace std;

int n, r;

void solve ()
{
    int d = 0, x, a [100000];
    while (n > 0)
    {
        x = n % r;
        n = n / r;
        a [d] = x;
        d++;
    }

    for (int i = d; i >= 1; i--)
    {
        cout << a [i - 1];
    }
}

int main ()
{
    cin >> n >> r;
    solve ();
    return 0;
}