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

const int maxn = 1e5 + 10;

int n, k;
int a[maxn];

namespace sub2 {
	long long dp[510][510];

	void process() {
		for (int i = 0; i <= k; i++) {
	    	for (int j = 0; j <= n; j++) {
	    		dp[i][j] = -1e18;
	    	}
	    }

	    dp[0][0] = 0;

	    for (int x = 1; x <= k; x++) {
	    	for (int i = 1; i <= n; i++) {
	    		int Min = 1e9;
	    		for (int j = i; j <= n; j++) {
	    			Min = min(Min, a[j]);
	    			dp[x][j] = max(dp[x][j], dp[x - 1][i - 1] + Min);
	    		}
	    	}
	    }

	    cout << dp[k][n];
	}
}

namespace sub3 {
	vector<long long> dp_pre, dp_cur;

	void process() {
		dp_pre.resize(n + 1, -1e18);
		dp_cur.resize(n + 1, -1e18);

	    dp_pre[0] = 0;

	    for (int x = 1; x <= k; x++) {
	    	for (int i = 1; i <= n; i++) {
	    		int Min = 1e9;
	    		for (int j = i; j <= min(n, i + 50); j++) {
	    			Min = min(Min, a[j]);
	    			dp_cur[j] = max(dp_cur[j], dp_pre[i - 1] + Min);
	    		}
	    	}
	    	swap(dp_pre, dp_cur);
	    }

	    cout << dp_pre[n];
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("CAU5.INP", "r", stdin);
    freopen("CAU5.OUT", "w", stdout);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    sub2::process();

    return 0;
}