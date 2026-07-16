/*#include <bits/stdc++.h>
using namespace std;
long long n, s = 0;
long long d[10000];
void input ()
{
    long long x;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> x;
        d [x-10102010]++;
    }
}

void solve ()
{
    for (int i = 1; i <= 8000; i++)
    {
        if (d[i] > 0)
        {
            if (d[i] <= 5) s = s + 100;
            else s = s + 100 + d[i] - 5;
        }
    }
    cout << s;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    input ();
    solve ();
    return 0;
}
Cách làm của thầy Vinh. Wrong answer on test 1
*/
#include <bits/stdc++.h>
using namespace std;

const int MIN = 10102010;
const int MAX = 10109999;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int K, T, total_fee = 0;
    cin >> K;
    int count[MAX - MIN + 1] = {0};

    for (int i = 0; i < K; ++i) {
        cin >> T;
        count[T - MIN]++;
    }

    for (int j = 0; j < (MAX - MIN + 1); ++j) {
        int p = count[j];
        if (p == 0) continue;

        if (p <= 5) {
            total_fee += 100;
        } else {
            total_fee += 100 + (p - 5);
        }
    }

    cout << total_fee << endl;
    return 0;
}