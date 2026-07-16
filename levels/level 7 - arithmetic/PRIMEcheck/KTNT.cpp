#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 4) == 0) return false;
    }
    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    int cnt = 0;
    while(t--) {
        int n;
        cin >> n;
        if (checkPrime(n)) cnt++;
    }
    cout << cnt << endl;

    return 0;
}