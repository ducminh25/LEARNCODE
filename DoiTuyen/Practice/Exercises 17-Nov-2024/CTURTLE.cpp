#include <bits/stdc++.h>
using namespace std;

long long minDis(long long a, long long b, long long c) {
    vector<long long> pos = {a, b, c};
    sort(pos.begin(), pos.end());
    
    long long minn = LLONG_MAX;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            for (int k = -1; k <= 1; k++) {
                long long x = pos[0] + i;
                long long y = pos[1] + j;
                long long z = pos[2] + k;
                
                if (abs(x - pos[0]) <= 1 && abs(y - pos[1]) <= 1 && abs(z - pos[2]) <= 1) {
                    long long dist = abs(x - y) + abs(y - z) + abs(z - x);
                    minn = min(minn, dist);
                }
            }
        }
    }
    
    return minn;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CTURTLE.inp", "r")) {
        freopen("CTURTLE.inp", "r", stdin);
        freopen("CTURTLE.out", "w", stdout);
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << minDis(a, b, c) << "\n";
    }
    
    return 0;
}
