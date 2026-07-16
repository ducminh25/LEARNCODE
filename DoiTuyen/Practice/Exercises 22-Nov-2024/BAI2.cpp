#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

long long modMul(long long a, long long b) {
    return (a * b) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    if(fopen("BAI2.inp", "r")) {
        freopen("BAI2.inp", "r", stdin);
        freopen("BAI2.out", "w", stdout);
    }
    
    int N;
    cin >> N;

    vector<int> a(N);
    long long product = 1;
    int negcnt = 0, zero = 0;
    int maxNeg = INT_MIN;

    for (int i = 0; i < N; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            negcnt++;
            maxNeg = max(maxNeg, a[i]);
            product = modMul(product, -a[i]);
        } else if (a[i] > 0) {
            product = modMul(product, a[i]);
        } else {
            zero++;
        }
    }

    if (zero > 1) {
        cout << 0 << endl;
    } else if (zero == 1) {
        if (negcnt % 2 == 0) {
            cout << product << endl;
        } else {
            cout << 0 << endl;
        }
    } else {  // zero == 0
        if (negcnt % 2 == 0) {
            cout << product << endl;
        } else {
            // Chia cho -maxNeg để loại bỏ số âm lớn nhất
            long long result = product;
            result = (result * (-maxNeg) % MOD) % MOD;
            if (result < 0) result += MOD;
            cout << result << endl;
        }
    }

    return 0;
}