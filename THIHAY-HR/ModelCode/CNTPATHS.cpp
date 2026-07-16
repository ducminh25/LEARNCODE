/**
 * Code 1 giải quyết được bài toán về mặt độ phức tạp thời gian
 * nhưng sẽ báo lỗi tràn stack khi giải quyết các dạng cây "độc"
 */

// #include <bits/stdc++.h>
// using namespace std;

// const int MAXN = 200005;
// vector<int> adj[MAXN];
// int color[MAXN];
// int S[MAXN];
// long long ans;

// void dfs(int u, int p) {
//     int c = color[u];
//     int entry_val = S[c];

//     for (int v : adj[u]) {
//         if (v == p) continue;
        
//         int prev_child_val = S[c];
//         dfs(v, u);
//         int curr_child_val = S[c];
        
//         long long L = curr_child_val - prev_child_val;
//         ans += L * (L + 1) / 2;
//     }
//     S[c] = entry_val + 1;
// }

// void solve() {
//     int n;
//     if (!(cin >> n)) return;

//     ans = 0;
//     for (int i = 1; i <= n; ++i) {
//         adj[i].clear();
//         S[i] = 0; 
//     }

//     for (int i = 1; i <= n; ++i) cin >> color[i];
    
//     for (int i = 0; i < n - 1; ++i) {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }

//     dfs(1, 0);
//     for (int i = 1; i <= n; ++i) {
//         long long L = S[i];
//         ans += L * (L - 1) / 2;
//     }

//     cout << ans << "\n";
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     if(fopen("cntpaths.inp", "r")) {
//         freopen("cntpaths.inp", "r", stdin);
//         freopen("cntpaths.out", "w", stdout);
//     }

//     int t;
//     if (cin >> t)
//         while (t--) solve();

//     return 0;
// }

// Code ở dưới giải quyết được tràn stack với dạng đồ thị cây thẳng đứng hoặc star (test 31-40)
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int color[MAXN], S[MAXN], parent[MAXN], head[MAXN], entry_S[MAXN], before_S[MAXN];
long long ans;

void solve() {
    int n;
    if (!(cin >> n)) return;

    ans = 0;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        S[i] = 0;
        head[i] = 0;
    }

    for (int i = 1; i <= n; ++i) cin >> color[i];

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> st;
    st.push_back(1);
    parent[1] = 0;
    entry_S[1] = S[color[1]];

    while (!st.empty()) {
        int u = st.back();
        bool pushed = false;

        while (head[u] < adj[u].size()) {
            int v = adj[u][head[u]];
            head[u]++;
            if (v == parent[u]) continue;

            parent[v] = u;
            before_S[v] = S[color[u]]; 
            entry_S[v] = S[color[v]]; 
            st.push_back(v);
            pushed = true;
            break;
        }

        if (pushed) continue;

        S[color[u]] = entry_S[u] + 1;

        if (u != 1) {
            int p = parent[u];
            int cp = color[p];
            long long L = S[cp] - before_S[u];
            ans += L * (L + 1) / 2;
        }
        st.pop_back();
    }

    for (int i = 1; i <= n; ++i) {
        long long L = S[i];
        ans += L * (L - 1) / 2;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}