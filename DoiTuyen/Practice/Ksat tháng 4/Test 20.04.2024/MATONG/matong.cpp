#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll ans;
ll f(ll x)
{
    if (x == 1) return 1;
    ll count_div = 1;
    ll i = 2;
    while (i*i <= x)
    {
        ll d = 0;
        while (x % i == 0)
        {
            d++;
            x = x / i;
        }
        count_div *= d + 1;
        i++;
    }
    if (x > 1) count_div *= 2;
    return count_div;
}
int main()
{
    freopen("matong.inp","r",stdin);
    freopen("matong.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        ll x;
        cin >> x;
        ans += x * f(x);
    }
    cout << ans;
    return 0;
}
