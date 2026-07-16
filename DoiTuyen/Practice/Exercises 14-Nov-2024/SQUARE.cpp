#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
const int INF = 1e9;
int m, n, k;
int A[MAXN][MAXN];
long long ps[MAXN][MAXN];

long long sum(int r, int c) {
    return ps[r+k-1][c+k-1] - ps[r-1][c+k-1] - ps[r+k-1][c-1] + ps[r-1][c-1];
}

void input() {
    cin >> m >> n >> k;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
            ps[i][j] = A[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }

}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("SQUARE.inp", "r")) {
        freopen("SQUARE.inp", "r", stdin);
        freopen("SQUARE.out", "w", stdout);
    }

    long long minn = LLONG_MAX;
    int min_unique = INF;

    for (int i = 1; i <= m - k + 1; i++) {
        for (int j = 1; j <= n - k + 1; j++) {
            long long crsum = sum(i, j);
    
            set<int> uniH; // unique heights
            for (int r = i; r < i + k; r++) {
                for (int c = j; c < j + k; c++) {
                    uniH.insert(A[r][c]);
                }
            }

            int curr = uniH.size();
            if (curr < min_unique || (curr == min_unique && crsum < minn)) {
                minn = crsum;
                min_unique = curr;
            }
        }
    }
    cout << minn << endl;

    return 0;
}