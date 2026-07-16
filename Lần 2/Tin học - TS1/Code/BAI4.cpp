#include<bits/stdc++.h>
using namespace std;
const int MAXN  =  1e6 + 10;

int a[MAXN];

void solve() {
        int n, x;
        cin >> n >> x;
        map<int, int> mp;
        for (int i = 1; i <= n; i ++) {
                cin >> a[i];
                if (a[i] >= x) {
                        continue;
                } else {
                        mp[a[i]] ++;
                }
        }
        for (pair<int, int> p : mp) {
                int v = p.first;
                int c = p.second;
                if (v >= x) {
                        cout << "YES";
                        return;
                }
                mp[v + 1] += c / (v + 1);
                if (c % (v + 1)) {
                        cout << "NO";
                        return;
                }
        }
        cout << "YES";
}

int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);      cout.tie(0);
		freopen("Bai4.inp", "r", stdin);
		freopen("Bai4.out", "w", stdout);
        int TT = 1;
        cin >> TT;
        for(int TTT = 1; TTT <= TT; TTT ++) {
                solve();
                cout << '\n';
        }
}

