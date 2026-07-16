#include <bits/stdc++.h>
using namespace std;

long long sumdigit(long long n) {
    long long res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

long long productdigit(long long n) {
    long long res = 1;
    while (n > 0) {
        res *= n % 10;
        n /= 10;
    }
    return res;
}

bool checkZero(long long n) {
    while (n > 0) {
        if (n % 10 == 0) {
            return true;
        }
        n /= 10;
    }
    return false;
}

void findPDS(int N) {
    int cnt = 0;
    long long num = 1;
    while (cnt < N) {
        if(checkZero(num)) {
            cnt++;
            num++;
        }
        else {
            if (productdigit(num) % sumdigit(num) == 0) {
                cnt++;
            }
            num++;
        }
    }

    cout << num - 1 << '\n';
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("SOPDS.inp", "r")) {
        freopen("SOPDS.inp", "r", stdin);
        freopen("SOPDS.out", "w", stdout);
    }

    int N;
    cin >> N;

    findPDS(N);

    return 0;
}