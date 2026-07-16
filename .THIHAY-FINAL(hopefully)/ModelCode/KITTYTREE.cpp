#include <bits/stdc++.h>
using namespace std;

#define ll long long
struct Edge {
    int to;
    int w;
};
const int maxN = 1e5 + 10;
const ll vc = 10000000000000007;

vector<Edge> adj[maxN];
ll a[maxN];
ll dist[maxN];
int n, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("KITTYTREE.INP", "r")) {
        freopen("KITTYTREE.INP", "r", stdin);
        freopen("KITTYTREE.OUT", "w", stdout);
    }
    
    if (!(cin >> n)) return 0;
    
    for (int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; ++i) adj[i].clear();

    for (int i = 2; i <= n; i++) {
        int p, c;
        cin >> p >> c; 
        adj[p].push_back({i, c});
    }

    ans = 0;
    queue<int> q;
    q.push(1);
    
    dist[1] = 0; 

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        if (a[u] < dist[u]) {
            dist[u] = vc;
            ans++;
        }

        for (Edge &e : adj[u]) {
            int v = e.to;
            int w = e.w;

            if (dist[u] >= vc) {
                dist[v] = vc;
            } else {
                dist[v] = max(0LL, dist[u] + w);
            }
            
            q.push(v);
        }
    }
    cout << ans;
    
    return 0;
}