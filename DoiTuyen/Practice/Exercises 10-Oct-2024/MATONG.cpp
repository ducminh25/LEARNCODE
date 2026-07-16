#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000001;
int divisors[MAXN];

void initDiv() {
    for (int i = 1; i < MAXN; i++) {
        for (int j = i; j < MAXN; j += i) {
            divisors[j]++;
        }
    }
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    if (fopen ("MATONG.INP", "r")) {
        freopen ("MATONG.INP", "r", stdin);
        freopen ("MATONG.OUT", "w", stdout);
    }
    
    initDiv();
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += (long long)x * divisors[x];
    }
    cout << sum << endl;
    return 0;
}