#include <bits/stdc++.h>
using namespace std;

bool ktraNgoc(const string S, long long K) {
    for (long long i = 0; i <= S.length() - K; ++i) {
        for (long long j = i + 1; j <= S.length() - K; ++j) {
            bool duplicate = true;
            for (long long k = 0; k < K; ++k) {
                if (S[i + k] != S[j + k]) {
                    duplicate = false;
                    break;
                }
            }
            if (duplicate) return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen ("PHNT.INP", "r", stdin);
    freopen ("PHNT.OUT", "w", stdout);
    long long N;
    string S;
    cin >> N;
    cin.ignore();
    getline (cin, S);

    for (long long K = 1; K <= N; ++K) {
        if (!ktraNgoc(S, K)) {
            cout << K << endl;
            break;
        }
    }
    return 0;
}