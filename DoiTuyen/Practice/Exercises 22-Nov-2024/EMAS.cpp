#include <bits/stdc++.h>
using namespace std;

long long M, K, A, B;

long long diff(long long x) {
    long long dau = A + x * K;
    long long bap = B + (M - x) * K;
    return abs(dau - bap);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("EMAS.inp", "r")) {
        freopen("EMAS.inp", "r", stdin);
        freopen("EMAS.out", "w", stdout);
    }
    
    cin >> M >> K >> A >> B;
    
    long long left = 0, right = M;
    while (right - left > 3) {
        long long m1 = left + (right - left) / 3;
        long long m2 = right - (right - left) / 3;
        if (diff(m1) < diff(m2))
            right = m2;
        else
            left = m1;
    }
    
    long long min_diff = LLONG_MAX;
    for (long long i = left; i <= right; i++) {
        min_diff = min(min_diff, diff(i));
    }
    
    cout << min_diff << endl;
    
    return 0;
}