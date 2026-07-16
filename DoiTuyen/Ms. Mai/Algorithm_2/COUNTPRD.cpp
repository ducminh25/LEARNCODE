#include <bits/stdc++.h>
using namespace std;

int dem (long long N) {
    set<long long> ngto;
    if (N % 2 == 0)
    {
        ngto.insert(2);
        while (N % 2 == 0)
        {
            N /= 2;
        }
    }

    for (long long i = 3; i * i <= N; i += 2)
    {
        if (N % i == 0)
        {
            ngto.insert(i);
            while (N % i == 0) {
                N /= i;
            }
        }
    }

    if (N > 2)
    {
        ngto.insert(N);
    }
    return ngto.size();
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("COUNTPRD.inp", "r", stdin);
    freopen("COUNTPRD.out", "w", stdout);

    long long N;
    cin >> N;
    cout << dem(N) << endl;
    return 0;
}
