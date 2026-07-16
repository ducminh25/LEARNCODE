#include <bits/stdc++.h>
using namespace std;
int t, cnt = 0;
long long a, b;

// Kiểm tra số nguyên tố
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("PTBACNHAT.inp", "r")) {
        freopen("PTBACNHAT.inp", "r", stdin);
        freopen("PTBACNHAT.out", "w", stdout);
    }
    
    cin >> t;
    while(t--) {
        long long a, b;
        cin >> a >> b;
        if((a < 0 && b > 0 && abs(b) % abs(a) == 0) 
            || (a > 0 && b < 0 && abs(b) % abs(a) == 0)) {
            long long x = - b / a;
            if (isPrime(x)) cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}

/*
Phương trình bậc nhất ax + b = 0 (a != 0)
|a|, |b| <= 10^12
Nhập vào N (1 <= N <= 20) và N dòng chứa số nguyên a, b. Đếm số lượng phương trình có nghiệm nguyên dương và nguyên tố.
*/