#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
deque <int> q;
int n, k;
int a [N], dp [N];

int main ()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> a [i];

    dp [0] = 0;
    a [n + 1] = 0;
    int sum = 0;
    q.push_back (0);

    for (int i = 1; i <= n + 1; ++i)
    {
        // loại bỏ những phần tử không quan trọng trong đoạn cần xét
        while (q.size () && q.front () < i - k) q.pop_front ();
        dp [i] = dp[q.front ()] + a [i];
        sum += a [i];

        while (q.size () && dp [q.back ()] >= dp [i]) q.pop_back ();
        q.push_back (i);
    }

    cout << sum - dp [n + 1];

    return 0;
}