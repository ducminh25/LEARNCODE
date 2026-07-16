#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    long long n;
    cin >> n;
    while (!is_prime(n)) {
        n--;
    }

    cout << n << endl;
    return 0;
}