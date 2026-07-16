#include <bits/stdc++.h>
using namespace std;
int n;
int a[100005];
long long cnt = 0, sum = 0;

void input() {
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
}

void sol() {
    for(int i = 0; i < n; ++i) {
        if(a[i] % 3 == 0) {
            cnt++;
            sum += a[i] - 3;
        }
    }
    cout << cnt << endl << sum / 3 << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU1.INP", "r")) {
        freopen("CAU1.INP", "r", stdin);
        freopen("CAU1.OUT", "w", stdout);
    }
    input();
    sol();

    return 0;
}