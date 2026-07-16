#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
vector<int> adj[MAXN];
bool visited[MAXN];
int n, m, k;

int bfs(int start_node) {
    if (visited[start_node])
        return 0;
    queue<int> q;
    q.push(start_node);
    visited[start_node] = true;
    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    return count;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    int central_component_size = bfs(1);

    cout << central_component_size - 1 << endl;

    if (central_component_size - 1 >= k) {
        cout << 0 << endl;
    } else {
        int total_components = 1;
        for (int i = 2; i <= n; ++i) {
            if (!visited[i]) {
                bfs(i);
                total_components++;
            }
        }
        cout << total_components - 1 << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    if (fopen("FESTIVAL.INP", "r")) {
        freopen("FESTIVAL.INP", "r", stdin);
        freopen("FESTIVAL.OUT", "w", stdout);
    }

    solve();

    return 0;
}