#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int freq[MAX + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen ("CAU2.INP", "r")) {
        freopen ("CAU2.INP", "r", stdin);
        freopen ("CAU2.OUT", "w", stdout);
    }
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    int max_freq = 0;
    for (int i = 1; i <= MAX; i++)
         max_freq = max(max_freq, freq[i]);

    cout << max_freq << endl;
    return 0;
}