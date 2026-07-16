// Kiếm tra số nguyên tố (bản nâng cao)
#include <bits/stdc++.h>
using namespace std;

bool isPrime (long long a) {
    if (a < 2) return 0;
    if (a == 2 || a == 3) return 1;
    if (a % 2 == 0 || a % 3 == 0) return 0;
    long long sqrta = sqrt(a);
    for (int j = 5; j <= sqrta; j += 6) {
        if (a % j == 0 || a % (j + 2) == 0) return 0;
    }
    return 1;
}

int main () {
    long long n;
    cin >> n;
    if (isPrime(n)) cout << "YES";
    else cout << "NO";
    return 0;
}

// 190909097