#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

vector<int> sumOfDivisors(MAXN + 1, 0);
vector<int> abundant(MAXN + 1, 0);
vector<int> abundantCount(MAXN + 1, 0);

void precompute() {
    for (int i = 1; i <= MAXN; i++) {
        for (int j = 2 * i; j <= MAXN; j += i) {
            sumOfDivisors[j] += i;
        }
    }
    for (int i = 2; i <= MAXN; i++) {
        if (sumOfDivisors[i] > i) {
            abundant[i] = 1;
        }
    }
    for (int i = 1; i <= MAXN; i++) {
        abundantCount[i] = abundantCount[i - 1] + abundant[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    precompute();

    int t, L, R;
    cin >> t;
    vector <int> ans;
    while (t--) {
        cin >> L >> R;
        ans.push_back(abundantCount[R] - abundantCount[L - 1]);
    }
    for (auto x : ans) cout << x << "\n";
    return 0;
}

// số phong phú