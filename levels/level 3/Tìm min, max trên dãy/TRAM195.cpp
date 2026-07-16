#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    int a [n], b [n];
    for (int i = 0; i < n; i++)
    {
        cin >> a [i] >> b [i];
    }
    int s = 0, maxx = 0;
    for (int i = 0; i < n; i++)
    {
        s += b [i] - a [i];
        if (s > maxx)
        {
            maxx = s;
        }
    }
    cout << maxx;
    return 0;
}