#include <bits/stdc++.h>
using namespace std;

long long comb2(long long x) {
    return (x * (x - 1)) / 2;
}

long long comb3(long long x) {
    return (x * (x - 1) * (x - 2)) / 6;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    if(fopen("BOBA.inp", "r")) {
        freopen("BOBA.inp", "r", stdin);
        freopen("BOBA.out", "w", stdout);
    }

    int N, Q;
    cin >> N >> Q;
    
    vector<int> A(N + 1);
    vector<int> cntE(N + 1, 0), cntO(N + 1, 0);
    
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
        cntE[i] = cntE[i - 1];
        cntO[i] = cntO[i - 1];
        if (A[i] % 2 == 0) {
            cntE[i]++;
        } else {
            cntO[i]++;
        }
    }
    
    while (Q--) {
        int L, R;
        cin >> L >> R;
        
        int evens = cntE[R] - cntE[L - 1];
        int odds = cntO[R] - cntO[L - 1];

        long long res = comb3(evens) + comb2(odds) * evens;
        cout << res << "\n";
    }

    return 0;
}
