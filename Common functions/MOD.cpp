// Các phép toán với số dư MOD
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

long long safeMod(long long a) {
    return ((a % MOD) + MOD) % MOD;
}

long long add(long long a, long long b) {
    return safeMod(safeMod(a) + safeMod(b));
}

long long subtract(long long a, long long b) {
    return safeMod(safeMod(a) - safeMod(b));
}

long long multiply(long long a, long long b) {
    return safeMod(safeMod(a) * safeMod(b));
}

long long power(long long base, long long exp) {
    long long result = 1;
    base = safeMod(base);
    while (exp > 0) {
        if (exp & 1) result = multiply(result, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return result;
}

long long sumArray(vector<long long>& arr) {
    long long sum = 0;
    for (long long num : arr) {
        sum = add(sum, num);
    }
    return sum;
}

long long productArray(vector<long long>& arr) {
    long long product = 1;
    for (long long num : arr) {
        product = multiply(product, num);
    }
    return product;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    long long a, b; 
    int n;
    vector<long long> arr;
    cin >> a >> b >> n;
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "1. (a + b) % MOD = " << add(a, b) << endl;
    cout << "2. (a - b) % MOD = " << subtract(a, b) << endl;
    cout << "3. (a * b) % MOD = " << multiply(a, b) << endl;
    cout << "4. (a^b) % MOD = " << power(a, b) << endl;
    cout << "5. Sum of array % MOD = " << sumArray(arr) << endl;
    cout << "6. Product of array % MOD = " << productArray(arr) << endl;

    return 0;
}

/*
1844628
2847193
5
4589242
243524
223443
555
4
1. (a + b) % MOD = 4691821
2. (a - b) % MOD = 998997442
3. (a * b) % MOD = 11892440
4. (a^b) % MOD = 838280003
5. Sum of array % MOD = 5056768
6. Product of array % MOD = 273974542
*/