#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
stack<int> st;
int n, top, t;

void output() {
    stack<int> st1 = st;
    int d = 0, a[10005];
    while (!st1.empty()) {
        d++;
        a[d] = st1.top();
        st1.pop();
    }
    for (int i = d; i >= 1; --i) cout << a[i] << ' ';
    cout << endl;
}

void solve() {
    cin >> n;
    top = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            cin >> t;
            st.push(t);
            output();
        }
        else {
            if (st.empty()) {
                cout << -1;
                break;
            }
            x = st.top();
            st.pop();
            cout << x << ' ';
            output();
        }
    }
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    solve();
    return 0;
}
