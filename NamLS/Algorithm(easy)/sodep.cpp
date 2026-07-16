// N là số đẹp nếu tổng các chữ số của N bằng tổng các chữ số của tất cả các thừa số nguyên tố được phân tích ra từ N.
// Hãy đếm các số đẹp trong đoạn [a, b].
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
bool is_prime[maxn];
vector<int> primes;

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    int sq = sqrt(maxn);
    for (int i = 2; i <= sq; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= maxn; j += i)
                is_prime[j] = false;
        }
    }
    for (int i = 2; i <= maxn; ++i) {
        if (is_prime[i])
            primes.push_back(i);
    }
}

vector<pair<long long, int>> factorize(long long n) {
    vector<pair<long long, int>> res;
    for (int p : primes) {
        if (1LL * p * p > n) break;
        int count = 0;
        while (n % p == 0) {
            count++;
            n /= p;
        }
        if (count > 0)
            res.push_back({p, count});
    }
    if (n > 1)
        res.push_back({n, 1});
    return res;
}

int sumDigit(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("sodep.inp", "r")) {
        freopen("sodep.inp", "r", stdin);
        freopen("sodep.out", "w", stdout);
    }

    sieve();
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    while (a <= b) {
        vector<pair<long long, int>> res = factorize(a);
        int sum = 0;
        for (size_t i = 0; i < res.size(); ++i) {
            sum += sumDigit(res[i].first) * res[i].second;
        }

        int sum2 = sumDigit(a);
        if (sum == sum2)
            cnt++;
        a++;
    }
    cout << cnt;

    return 0;
}