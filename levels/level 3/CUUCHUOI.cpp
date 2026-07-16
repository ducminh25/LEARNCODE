#include <bits/stdc++.h>
using namespace std;

long long i, j, k, n, m, x;
long long a [1000], b [1000];
void input ()
{
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) cin >> a [i];
}

void cau1 ()
{
    m = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (a [i] % 2 == 0)
        {
            m++;
            b [m] = a [i];
        }
    }
}

void outB ()
{
    for (int i = 1; i <= m; i++) 
        cout << b [i] << " ";
    cout << endl;
}

void cau2 ()
{
    for (i = k; i <= m - 1; i++)
        b [i] = b [i + 1];
    m--;
}

void cau3 ()
{
    m++;
    for (int i = m; i >= 2; i--)
        b [i] = b [i - 1];
    b [1] = x;
    
}

void cau4 ()
{
    int t = b [1];
    for (int i = 1; i <= m - 1; i++) 
        b [i] = b [i + 1];
    b [m] = t;
}

int main ()
{
    input ();
    cau1 ();
    outB ();
    cau2 ();
    outB ();
    cau3 ();
    outB ();
    cau4 ();
    outB ();
    return 0;
}