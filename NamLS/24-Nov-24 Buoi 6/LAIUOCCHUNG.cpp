#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int sumdigit(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int specialGCD(int a, int b) {
    int g = gcd(a, b);
    int maxSum = 0, res = 1;
    
    for (int i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            int sum1 = sumdigit(i);
            if (sum1 > maxSum) {
                maxSum = sum1;
                res = i;
            }
            
            if (i != g / i) {
                int sum2 = sumdigit(g / i);
                if (sum2 > maxSum) {
                    maxSum = sum2;
                    res = g / i;
                }
            }
        }
    }
    
    return sumdigit(res);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("LAIUOCCHUNG.inp", "r")) {
        freopen("LAIUOCCHUNG.inp", "r", stdin);
        freopen("LAIUOCCHUNG.out", "w", stdout);
    }
    
    int a, b;
    cin >> a >> b;
    cout << specialGCD(a, b) << endl;
    
    return 0;
}