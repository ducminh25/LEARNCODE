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

const int maxn = 1e6 + 10;

int n, k;
int h[maxn];
int link[maxn], posUp;

namespace sub1 {
	int suf[maxn];

	void process() {	
		for (int i = n; i > 0; i--) {
			suf[i] = max(suf[i + 1], h[i]);
		}
		long long Ans = 0;
		int cur_h = suf[1];
		for (int i = 1; i <= n; i++) {
			Ans += cur_h - h[i];
		}
		cout << Ans;
	}
}

namespace sub2 {
	int suf[maxn];

	void process() {	
		for (int i = n; i > 0; i--) {
			suf[i] = max(suf[i + 1], h[i]);
		}
		long long Ans = 0;
		int cur_h = h[1];
		for (int i = 1; i <= n; i++) {
			if (cur_h < h[i]) {
				cur_h = suf[i];
			}
			Ans += cur_h - h[i];
		}
		cout << Ans;
	}
}

namespace sub3 {
	int suf[maxn];

	void process() {	
		for (int i = n; i > 0; i--) {
			suf[i] = max(suf[i + 1], h[i]);
		}
		long long Ans = 1e18;
		for (int j = 1; j <= n; j++) {
			int cur_h = h[j];
			long long sum = 0;
			for (int i = 1; i <= n; i++) {
				if (cur_h < h[i]) {
					cur_h = suf[i];
				}
				sum += cur_h - h[i];
			}
			Ans = min(Ans, sum);
		}

		cout << Ans;
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("CAU2.INP", "r", stdin);
    freopen("CAU2.OUT", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	cin >> h[i];
    }

    if (k == 0) {
    	sub1::process();
    } else if (k == -1) {
    	sub2::process();
    } else {
    	sub3::process();
    }

    return 0;
}