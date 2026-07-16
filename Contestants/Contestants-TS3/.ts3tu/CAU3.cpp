#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define pii pair<int, int>

using namespace std;

template <class T>
T gcd(T a, T b) {
    if (a == 0) return b;
    if (b == 0) return a;
    int shift = __builtin_ctzll((long long)(a | b));
    a >>= __builtin_ctzll((long long)a);
    do {
        b >>= __builtin_ctzll((long long)b);
        if (a > b) swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

long long lcm(long long x, long long y) {
	return x / gcd(x, y) * y;
}

const int maxn = 1e6 + 10;

int n, m;
int a[maxn], b[maxn];

const int lim = 1e6 + 5;

int lp[lim];
int d[lim]; 
int cnt[lim];
vector<int> primes;

void linearSieve() {
	d[1] = 1;
	
	for (int i = 2; i < lim; ++i) {
		if (lp[i] == 0) {
			lp[i] = i;
			d[i] = 2;
			cnt[i] = 1;
			primes.push_back(i);
		}
		
		for (int p : primes) {
			if (p > lp[i] || (long long)i * p >= lim) break;
			
			lp[i * p] = p;
			
			if (p == lp[i]) {
				cnt[i * p] = cnt[i] + 1;
				d[i * p] = d[i] / (cnt[i] + 1) * (cnt[i] + 2);
			} else {
				cnt[i * p] = 1;
				d[i * p] = d[i] * 2;
			}
		}
	}
}

int vis[lim];
void Fact(int n) {
	while (n > 1) {
		int p = lp[n];
		vis[p] = 1;
		n /= p;
	}
}

bool check(int n) {
	// cerr << "Fact : " << n << ":\n";
	while (n > 1) {
		int p = lp[n];
		// cerr << p << ' ';
		if (vis[p]) return 0;
		n /= p;
	}
	// cerr << '\n';
	return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("CAU3.INP", "r", stdin);
    freopen("CAU3.OUT", "w", stdout);

    linearSieve();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
    	cin >> b[i];
    }

    for (int i = 1; i <= m; i++) {
    	Fact(b[i]);
    }

    int Ans = 0;
    for (int i = 1; i <= n; i++) if (check(a[i])) {
    	Ans++;
    }

    cout << Ans;

    return 0;
}