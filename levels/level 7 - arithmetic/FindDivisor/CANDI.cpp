#include <bits/stdc++.h>
using namespace std;
long long n;

int main () {
    ios_base :: sync_with_stdio (false);
    cin.tie(0); cout.tie(0);

    cin >> n;

    long long s = 0;
    for (int i = 2; i <= int(sqrt(n)); i++)
        if (n % i == 0) s += 2;
    if (sqrt(n) == int(sqrt(n))) s--;
    cout << s + 1;

    return 0;
}