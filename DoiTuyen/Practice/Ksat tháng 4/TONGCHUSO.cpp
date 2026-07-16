#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen ("TONGCHUSO.INP", "r", stdin);
    freopen ("TONGCHUSO.OUT", "w", stdout);
    long long n;
    cin >> n;
    long long sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n = n / 10;
    }
    cout << sum << endl;
    return 0;
}