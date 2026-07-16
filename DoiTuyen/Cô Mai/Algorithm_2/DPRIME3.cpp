/*#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, k = 20000;
bool prime[20002], d = true;
bool check(ll n) {
    for(int i = 2; i <= (int)sqrt(n); ++i) {
        if(n% i == 0) return false;
    }
    return n > 1;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    prime[0] = prime[1] = true;
    for (int i = 2; i <= (int)sqrt(k); ++i) {
        if(!prime[i])
            for(int j = i*i; j <= k; j+=i) {
                prime[j] = true;
            }
    }
    for(int i = 3; i <= k; ++i) {
        if(!prime[i]) {
            ll kq = 4 + i *  i;
            if (kq > n) break;
            if(check (kq)) {
                d = false;
                cout << 2 << " " << i <<  " " << kq << endl;
            }
        }
    }
    if (d) {
        cout << -1;
    }
    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e9;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    freopen ("DPRIME3.inp", "r", stdin);
    freopen ("DPRIME3.out", "w", stdout);
    
    int n;
    cin >> n;

    bool found = false;
    for (int x = 2; x * x <= n; x++) {
        if (isPrime(x)) {
            for (int y = x; y * y <= n - x * x; y++) {
                if (isPrime(y)) {
                    int z = x * x + y * y;
                    if (isPrime(z)) {
                        cout << x << " " << y << " " << z << endl;
                        found = true;
                    }
                }
            }
        }
    }

    if (!found) {
        cout << "-1" << endl;
    }

    return 0;
}