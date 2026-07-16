#include <bits/stdc++.h>
using namespace std;
int N;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    int sq = sqrt(n);
    for(int i = 5; i <= sq; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;

    return true;
}

int dSum(int n) {
    int sum = 0;
    while (n > 0) {
        int di = n % 10;
        sum += di * di;
        n /= 10;
    }
    return sum;
}

bool check(int n) {
    return isPrime(dSum(n));
}

int find(int N) {
    int cnt = 0;
    int num = 1;
    while(cnt < N) {
        if(check(num)) cnt++;
        if(cnt == N) return num;
        num++;
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("cau22023.inp", "r")) {
        freopen("cau22023.inp", "r", stdin);
        freopen("cau22023.out", "w", stdout);
    }
    cin >> N;
    cout << find(N) << endl;

    return 0;
}