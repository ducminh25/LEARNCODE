#include <bits/stdc++.h>
using namespace std;

vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> divisors = findDivisors(n);
        for (int div : divisors) {
            cout << div << ' ';
        }
        cout << '\n';
    }

    return 0;
}

// Tổng độ phức tạp: O(t * (sqrt(n) + d log d)), với t là số lượng truy vấn, d là số lượng ước số của n.