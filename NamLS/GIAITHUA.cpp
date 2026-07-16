#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
int a[maxn], n, k;
map<int, int> mp;

void solve() {
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] >= k) continue;
        else mp[a[i]]++;
    }

    for (pair<int, int> p : mp) {
        int v = p.first;
        int c = p.second;
        if (v >= k) {
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
    cin.tie(0); cout.tie(0);
    
    if(fopen("GIAITHUA.inp", "r")) {
        freopen("GIAITHUA.inp", "r", stdin);
        freopen("GIAITHUA.out", "w", stdout);
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }

    return 0;
}

/*
Cho dãy số nguyên gồm n phần tử a1, a2, ..., an và số nguyên dương k. Yêu cầu: kiểm tra xem a1! + a2! + a3! + ...+ an! có chia hết cho k! hay không. Có t truy vấn.

Test mẫu:
INPUT:
2
2 3
3 4
3 4
1 2 5
--> OUTPUT: 
YES
NO
*/