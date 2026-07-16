#include <bits/stdc++.h>
using namespace std;

int n, k, a [INT_MAX], res [INT_MAX];
deque <int> q;

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> n >> k;
    for (int i = 0; i <= n; ++i)
        cin >> a [i];

    for (int i = 1; i <= n; ++i)
    {
        while (q.size () && a [q.back ()] > a [i]) q.pop_back ();
        q.push_back (i);
        if (q.front () + k <= i) q.pop_front ();
        if (i >= k - 1) res [i - k + 1] = a [q.front ()];
    }

    for (int i = k; i <= n; ++i)
        cout << res [i] << endl;
    
    return 0;
}