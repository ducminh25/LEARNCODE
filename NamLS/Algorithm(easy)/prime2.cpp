#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
bool is_prime[maxn];

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < maxn; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < maxn; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

string toString(int n) {
    string res = "";
    while (n > 0) {
        res = char(n % 10 + '0') + res;
        n /= 10;
    }
    return res;
}

int toInt(string s) {
    int res = 0;
    for(int i = 0; i < s.size(); ++i) {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

bool check(int n) {
    string s = toString(n);
    int len = s.length();
    if (len == 1) return is_prime[n];
    
    for (int i = 0; i < len; ++i) {
        string rotated = s.substr(i) + s.substr(0, i);
        if (!is_prime[toInt(rotated)]) return false;
    }
    return true;
}

int cnt(int N) {
    int count = 0;
    for (int i = 2; i < N; ++i) {
        if (check(i)) count++;
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("prime2.inp", "r")) {
        freopen("prime2.inp", "r", stdin);
        freopen("prime2.out", "w", stdout);
    }
    
    sieve();
    int n;
    cin >> n;
    cout << cnt(n) << endl;

    return 0;
}