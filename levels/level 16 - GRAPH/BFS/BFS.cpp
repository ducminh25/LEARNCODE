#include <bits/stdc++.h>
using namespace std;
int vis[100005] = {0};
int n, m, s, f;
vector<int> a[100005];
int res = 0;
queue<int> q;

void trace(int f, int s) {
    int d = 0, res[100005];
    // q[1] = p;
    while (f != s) {
        d++;
        res[d] = f; //vis[p]
        f = vis[f];
    }
    d++; res[d] = s;
    cout << d << endl;
    for (int i = d; i >= 1; --i) cout << res[i] << ' ';
}

void bfs() {
    int u, v;
    vis[s] = n + 1;
    q.push(s);
    while (!q.empty()) {
        u = q.front(); q.pop();
        // cout << u << endl;
        for (int i = 0; i < a[u].size(); ++i) {
            v = a[u][i];
            // cout << u << ' ' << v << endl;
            if (vis[v] == 0) {
                vis[v] = u;
                if (v == f) {
                    trace (f, s);
                    return;
                }
                else q.push(v);
            }
        }
    }
    cout << 0;
}

void input() {
    cin >> n >> m >> s >> f;
    int x, y;
    for (int i = 1; i <= m; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        // a[y].push_back(x);
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BFS.inp", "r")) {
        freopen("BFS.inp", "r", stdin);
        freopen("BFS.out", "w", stdout);
    }

    input();
    bfs();

    return 0;
}
