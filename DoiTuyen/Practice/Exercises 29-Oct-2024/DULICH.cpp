#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 1e8;
struct edge {
    int v, w;
};
vector<edge> adj[MAXN]; // Lưu các đỉnh cùng các lần thăm
int dist[MAXN];

// Vừa mới tìm hiểu được thuật toán đồ thị ni trên mạng:D
void dijkstra(int s)  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const edge& e : adj[u]) {
            int v = e.v;
            int w = e.w;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("DULICH.INP", "r")) {
        freopen("DULICH.inp", "r", stdin);
        freopen("DULICH.out", "w", stdout);
    }
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) dist[i] = INF;

    //Input graph       
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijkstra(1);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << -1 << " ";
        else cout << dist[i] << " ";
    }

    return 0;
}