#include <bits/stdc++.h>
using namespace std;
bool isPrime (int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

int powerInFactorial(int n, int p) {
    int k = 0;
    while (n >= p) {
        k += n / p;
        n /= p;
    }
    return k;
}

int countDivisorsOfFactorial(int n) {
    int totalDivisors = 1;
    for (int p = 2; p <= n; ++p) {
        if (isPrime(p)) {
            int k = powerInFactorial(n, p);
            totalDivisors *= (k + 1);
        }
    }
    return totalDivisors - 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    cout << countDivisorsOfFactorial(n) << endl;

    return 0;
}
