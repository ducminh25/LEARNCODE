#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int divisors[MAXN];

void initDiv () {
    for (int i = 1; i < MAXN; i++)
        for (int j = i; j < MAXN; j += i) 
            divisors[j]++;
}

bool checkPrime (int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    if(fopen("CAU3.inp", "r")) {
        freopen("CAU3.inp", "r", stdin);
        freopen("CAU3.out", "w", stdout);
    }
    initDiv ();
    int a, b;
    cin >> a >> b;

    int cnt = 0;
    while (b - a >= 0) {
        if(checkPrime(divisors[a])) cnt++;
        a++;
    }
    cout << cnt << endl;

    return 0;
}