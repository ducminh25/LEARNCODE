#include <bits/stdc++.h>
using namespace std;

const int maxx = 1000005;
long long res = 0, t = 0;
int n, m;
int a [1600][1600];
bool p [maxx];

void sieve ()
{
    int j;
    for (int i = 1; i <= maxx; i++) p[i] = true;
    p [0] = false; 
    p [1] = false;
    for (int i = 2; i * i <= maxx; i++)
    {
        if (p[i] == true)
        {
            for (j = i * i; j <= maxx; j += i)
            {
                p[j] = false;
            }
        }
    }
}

void check (int x, int y)
{
    if (a[x][y] == 0) return;
    int k = a[x][y];
    if (p[k])
    {
        res += k;
        t++;
    }
    for (int i = 1; i <= 5; ++i)
    {
        if (i + y > m) break;
        k = k * 10 + a[x][y + i];
        if (p[k])
        {
            res += k;
            t++;
        }
    }
    k = a[x][y];
    for (int i = 1; i <= 5; ++i)
    {
        if ((x + i > n) || (i + y > m)) break;
        k = k * 10 + a[x + i][y + i];
        if (p[k])
        {
            res += k;
            t++;
        }
    }
    k = a[x][y];
    for (int i = 1; i <= 5; ++i)
    {
        if (x + i > n) break;
        k = k * 10 + a[x + i][y];
        if (p[k])
        {
            res += k;
            t++;
        }
    }
}

void solve ()
{
    sieve ();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            check (i, j);
    cout << t << " " << res;
}

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    solve ();
    return 0;
}