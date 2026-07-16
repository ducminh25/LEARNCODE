#include <bits/stdc++.h>
using namespace std;

long long combinatorics(long long a, long long b)
{
    long long res = 1;
    for (long long i = 1; i <= b; i++)
        res = res * (a - b + i) / i;

    return res;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    long long a, b;
    cin >> a >> b;
    cout << a << "C" << b << " = " << combinatorics(a, b);
    return 0;
}

// combinatorics : tổ hợp