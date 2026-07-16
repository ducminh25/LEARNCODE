#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define FOR(i, a, b) for (ll i = a; i <= b; ++i)
#define FOD(i, a, b) for (ll i = a; i < b; ++i)
#define io(name)                           \
    if (fopen(name ".INP", "r"))           \
    {                                      \
        freopen(name ".INP", "r", stdin);  \
        freopen(name ".OUT", "w", stdout); \
    }
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ms(a, v) memset(a, v, sizeof(a));

stringstream ss;

ll sum(int n)
{
    ll sum = 0;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i) sum += n / i;
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    io("TONGUOC")
    ll n,a;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        cout << sum(a) << " ";
    }

    return 0;
}

