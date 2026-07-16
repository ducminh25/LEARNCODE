#include <bits/stdc++.h>
using namespace std;
long long m;

long long maxOrigin(long long n) {
    long long product = 1;
    int i = 2;
    int sq = int(sqrt(n));
    while (i <= sq) {
        if (n % i == 0)
            product *= i;
        while (n % i == 0) n /= i;
        i++;
    }
    if (n > 1) product *= n;
    return product;
}

void sol() {
    while (m > 1) {
        if(maxOrigin(m) == m) {
            cout << m;
            return;
        }
        m--;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> m;
    sol();

    return 0;
}