#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, K;
int A[100001];
string s;
void Solve() {
    cin >> N >> K;
    cin >> s;
    for (int i = 0; i < K; i++) cin >> A[i];
    ll distance = 0;
    for (int i = 0; i < N - 1; i++) {
        if (s[i] == s[i + 1])
            distance += 2;
        else
            distance += 1;
    }
    for (int i = 0; i < K; i++) {
        A[i] -= 1;
        if (s[A[i]] == '0') {
            if (A[i] + 1 < N && s[A[i] + 1] == '1') distance += 1;
            if (A[i] - 1 >= 0 && s[A[i] - 1] == '1') distance += 1;
            if (A[i] + 1 < N && s[A[i] + 1] == '0') distance -= 1;
            if (A[i] - 1 >= 0 && s[A[i] - 1] == '0') distance -= 1;
            s[A[i]] = '1';
        } else {
            if (A[i] + 1 < N && s[A[i] + 1] == '1') distance -= 1;
            if (A[i] - 1 >= 0 && s[A[i] - 1] == '1') distance -= 1;
            if (A[i] + 1 < N && s[A[i] + 1] == '0') distance += 1;
            if (A[i] - 1 >= 0 && s[A[i] - 1] == '0') distance += 1;
            s[A[i]] = '0';
        }
        cout << distance << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    Solve();
    return 0;
}
