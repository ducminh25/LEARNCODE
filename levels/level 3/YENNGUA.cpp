#include <bits/stdc++.h>
using namespace std;
int m, n;
int a[1005][1005];

void input() {
    cin >> m >> n;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) cin >> a[i][j];
    }
}

bool check_min(int x, int y) {
    for(int i = 1; i <= n; ++i)
        if(a[x][y] > a[x][i]) return false;
    
    return true;
}

bool check_max(int x, int y) {
    for(int i = 1; i <= m; ++i)
        if(a[i][y] > a[x][y]) return false;

    return true;
}

void sol() {
    int d = 0;
    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(check_max(i, j) && check_min(i, j)) {
                cout << i << " " << j << endl;
                ++d;
            }
        }
    }
    if(d == 0) cout << "NO" << endl;
}

int main() {
    ios_base :: sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    input();
    sol();

    return 0;
}