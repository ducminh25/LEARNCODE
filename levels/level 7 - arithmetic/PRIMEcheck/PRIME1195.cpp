#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

vector<int> findDiv(int n) {
    vector<int> divisors;
    if (n <= 0) return divisors;
    
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n)
                divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    
    return divisors;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int m, n;
    cin >> m >> n;
    if(m == 1) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> div = findDiv(m);
    int minn = INT_MAX;
    for(int i = 0; i < div.size(); ++i) {
        if(isPrime(div[i])) 
            if(abs(div[i] - n) < minn) minn = abs(div[i] - n);
    }
    if(isPrime(n - minn) && m % (n - minn) == 0) cout << n - minn;
    if(isPrime(n + minn) && m % (n + minn) == 0) cout << " " << n + minn << endl;

    return 0;
}
