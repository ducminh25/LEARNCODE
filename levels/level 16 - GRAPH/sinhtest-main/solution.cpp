//Tran Huu Nam - huunam0@gmail.com - 3/2022
// Nhập dữ liệu từ bàn phím và in ra màn hình --> Không freopen

#include <bits/stdc++.h>
using namespace std;
long long n, k;

long long solve(long long n, long long k) {
    if (k % n == 0) return n;
    else return solve(k % n, k % n + n);
}

int main() {
    if(fopen("ECHNHAY.inp", "r")) {
        freopen("ECHNHAY.inp", "r", stdin);
        freopen("ECHNHAY.out", "w", stdout);
    }
    cin >> n >> k;
    cout << solve(n, k);

    return 0;
}