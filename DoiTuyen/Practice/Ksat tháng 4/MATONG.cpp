#include <bits/stdc++.h>
using namespace std;

long long countDivisors(long long X) {
    long long count = 0;
    for (long long i = 1; i <= sqrt(X); i++) {
        if (X % i == 0) {
            count++;
            if (X / i != i)
                count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen ("MATONG.INP", "r", stdin);
    freopen ("MATONG.OUT", "w", stdout);
    long long n;
    cin >> n;
    long long totalHoney = 0;

    for (long long i = 0; i < n; i++) {
        long long A;
        cin >> A;
        totalHoney += A * countDivisors(A);
    }

    cout << totalHoney << endl;
    return 0;
}