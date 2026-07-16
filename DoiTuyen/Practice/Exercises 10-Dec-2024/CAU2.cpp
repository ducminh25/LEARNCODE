#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define fi first
#define se second
const long long INF = 1e12 + 5;
const int MAXN = 1000005;
bool is_prime[MAXN];
vector<int> primes;
long long n;

void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAXN; ++i)
        if (is_prime[i])
            for (int j = i * i; j < MAXN; j += i)
                is_prime[j] = false;

    for (int i = 2; i < MAXN; ++i)
        if (is_prime[i]) primes.push_back(i);
}

vector<pair<int, int>> factorize(int n) {
    vector<pair<int, int>> res;
    for (int p : primes) {
        if (1LL * p * p > n) break;
        int cnt = 0;
        while (n % p == 0) {
            ++cnt;
            n /= p;
        }
        if (cnt > 0) res.push_back({p, cnt});
    }
    if (n > 1) res.push_back({n, 1});
    
    return res;
}

void solve() {
    auto factors = factorize(n);
    long long sumeven = 0, sumodd = 0;
    for (auto [prime, expo] : factors) {
        if (expo % 2 == 0) sumeven += expo;
        else sumodd += expo;
    }

    cout << sumeven << endl << sumodd << endl;
}

signed main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    if(fopen("CAU2.inp", "r")) {
        freopen("CAU2.inp", "r", stdin);
        freopen("CAU2.out", "w", stdout);
    }
    
    sieve();
    cin >> n;
    solve();

    return 0;
}

// 

/*
Cho số tự nhiên N (N ≥ 2), ta có thể phân tích N thành tích các thừa số nguyên tố với dạng N = P1^a1 x P2^a2 x ... Pk^ak , trong đó P1<P2< ... <Pk là các số nguyên tố và a1, a2, ..., ak>0. 
Gọi S là tổng các số mũ ai chẵn, Q là tổng các số mũ aj lẻ (1≤i,j≤k)
Vậy: S + Q = a1 + a2 + ... + ak.
Yêu cầu: Hãy đưa ra giá trị của S và Q
Dữ liệu vào: gồm một số tự nhiên N.
Kết quả: gồm 2 dòng
	Dòng thứ nhất ghi giá trị của S
	Dòng thứ hai ghi giá trị của P

*/