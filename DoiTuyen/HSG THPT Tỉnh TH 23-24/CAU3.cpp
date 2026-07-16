#include <bits/stdc++.h>
using namespace std;
const int maxn = 2300000;
int n, a[maxn], freq[maxn];

void input() {
    cin >> n;
    int tmp = pow(n, 2);
    for (int i = 1; i <= tmp; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }
}

void solve() {
    int minn = INT_MAX;
    int tmp = pow(n, 2);
    for (int i = 1; i <= tmp; ++i) {
        minn = min(minn, freq[a[i]] * a[i]);
    }
    cout << minn << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if(fopen("CAU3.inp", "r")) {
        
    }
}