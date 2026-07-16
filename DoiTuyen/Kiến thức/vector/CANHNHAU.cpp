/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("CANHNHAU.INP", "r", stdin);
    //freopen("CANHNHAU.OUT", "w", stdout);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end());
        adj[i].erase(unique(adj[i].begin(), adj[i].end()), adj[i].end());

        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << "0\n";
    }

    return 0;
}

*/

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector <int> adj[1005];
int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    freopen ("CANHNHAU.INP", "r", stdin);
    freopen ("CANHNHAU.OUT", "w", stdout);
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
            if (i != adj [i][j]) cout << adj [i][j] << " ";
        cout << "0\n";
        
    }
    
    return 0;
}
