#include <bits/stdc++.h>
using namespace std;

void factorize(int n) {
    int i = 2;
    int sq = sqrt(n);
    while (i <= sq) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
        i++;
    }
    if (n > 1) cout << n;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    long long n;
    cin >> n;
    factorize (n);

    return 0;
}
