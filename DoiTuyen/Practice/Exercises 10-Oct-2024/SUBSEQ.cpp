#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    if (fopen("SUBSEQ.INP", "r")) {
        freopen ("SUBSEQ.INP", "r", stdin);
        freopen ("SUBSEQ.OUT", "w", stdout);
    }
    
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] % a[j] == 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int max_len = *max_element(dp.begin(), dp.end());
    cout << max_len << endl;

    return 0;
}