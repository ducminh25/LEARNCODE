#include <bits/stdc++.h>
using namespace std;

long long cnt_substr(int len) {
    return (len * (len + 1)) / 2;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("QUACUATHANG.inp", "r")) {
        freopen("QUACUATHANG.inp", "r", stdin);
        freopen("QUACUATHANG.out", "w", stdout);
    }

    string S;
    cin >> S;
    int n = S.size();

    long long result = 0;
    vector<int> same(n, 0);

    for (int i = 0, len = 0; i < n; ++i) {
        len = 1;
        while (i + 1 < n && S[i] == S[i + 1]) {
            ++len;
            ++i;
        }
        result += cnt_substr(len);
        same[i] = len;
    }

    for (int mid = 0; mid < n; ++mid) {
        int l = mid - 1;
        int r = mid + 1;

        while (l >= 0 && r < n && S[l] == S[r] && S[l] != S[mid]) {
            result++;
            l--;
            r++;
        }
    }

    cout << result << "\n";
    return 0;
}

// 50%