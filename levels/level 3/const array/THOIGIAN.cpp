#include <bits/stdc++.h>
using namespace std;
int i, j, x, y, s;
int vertical [10] = {4, 2, 2, 2, 3, 2, 3, 2, 4, 3};
int horizontal [10] = {2, 0, 3, 3, 1, 3, 3, 1, 3, 3};

int ngang (int x, int y)
{
    s = 0;
    if (x < 10) s += horizontal [x];
    else s += horizontal [x % 10] + horizontal [x / 10];
    if (y < 10) s += horizontal [0] + horizontal [y];
    else s += horizontal [y % 10] + horizontal [y / 10];
    return s;
}

int doc (int x, int y)
{
    s = 0;
    if (x < 10) s += vertical [x];
    else s += vertical [x % 10] + vertical [x / 10];
    if (y < 10) s += vertical [0] + vertical [y];
    else s += vertical [y % 10] + vertical [y / 10];
    return s;
}
int main() 
{
    ios_base :: sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);
    cin >> x >> y;
    for (i = 0; i <= 23; ++i)
        for (j = 0; j <= 59; ++j)
        {
            if (ngang (i, j) == y && doc (i, j) == x)
            {
                if (j < 10) cout << i << ":0" << j << endl;
                else cout << i << ":" << j << endl;
                return 0;
            }
        }
    return 0;
}