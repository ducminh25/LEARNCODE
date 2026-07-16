#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, m, x;
vector<int> adj[MAXN];
bool vis[MAXN];

void dfs(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("MMUA.INP", "r")) {
        freopen("MMUA.INP", "r", stdin);
        freopen("MMUA.OUT", "w", stdout);
    }
    
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        if (c >= x) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count << endl;

    return 0;
}