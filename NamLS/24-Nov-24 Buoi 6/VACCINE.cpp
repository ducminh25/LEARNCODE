#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string s1, s2[1005];
int n;

void input() {
    cin >> n >> s1;
    for (int i = 0; i < n; ++i) cin >> s2[i];
}

void output() {
    int gcnt = 0, ccnt = 0;
    int m = s1.size();
    for (int i = 0; i < m; ++i) {
        if (s1[i] == 'G') gcnt++;
        if (s1[i] == 'C') ccnt++;
    }
    long long res = 0, ind = 1;
    for (int i = 1; i <= n; i++) {
        long long x, g1 = 0, c1 = 0;
        string p = s2[i - 1];
        x = p.size();
        for (int j = 0; j < x; ++j) {
            if (p[j] == 'G') g1++;
            if (p[j] == 'C') c1++;
        }
        if (res < gcnt * c1 + g1 * ccnt) {
            res = gcnt * c1 + g1 * ccnt;
            ind = i;
        }
    }
    
    cout << ind << endl;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("VACCINE.inp", "r")) {
        freopen("VACCINE.inp", "r", stdin);
        freopen("VACCINE.out", "w", stdout);
    }

    input();
    output();

    return 0;
}
