#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int countPrimeFactors(long long n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && isPrime(i)) {
            count++;
            while (n % i == 0) {
                n /= i;
            }
        }
    }
    return count;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    long long number;
    cin >> number;
    cout << countPrimeFactors(number) << endl;
    return 0;
}