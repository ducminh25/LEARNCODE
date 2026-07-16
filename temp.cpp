#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = 1e18;

int N;
long long S;
vector<int> Q, W, C;
vector<vector<int>> adj;
vector<vector<int>> children;
vector<vector<long long>> dp;

void build_tree_dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            children[u].push_back(v);
            build_tree_dfs(v, u);
        }
    }
}

void solve_dfs(int u) {
    // Process all children first
    for (int v : children[u]) {
        solve_dfs(v);
    }

    // dp_children[p] = min cost to get production p from all children subtrees combined
    vector<long long> dp_children(S + 1, INF);
    dp_children[0] = 0;

    // OPTIMIZATION: Merge DP tables of all children IN-PLACE
    for (int v : children[u]) {
        // Iterate main knapsack capacity (p1) downwards to prevent using an item from v multiple times
        for (int p1 = S; p1 >= 0; --p1) {
            if (dp_children[p1] == INF) continue;

            // Iterate through items from child v's knapsack
            for (int p2 = 1; p2 <= S; ++p2) { // p2=0 is identity, can be skipped
                if (dp[v][p2] == INF) continue;

                long long current_prod = (long long)p1 + p2;
                long long next_prod_idx = min((long long)S, current_prod);

                dp_children[next_prod_idx] = min(dp_children[next_prod_idx], dp_children[p1] + dp[v][p2]);
            }
        }
    }

    // Now, calculate final dp[u] using its own contribution and the combined children_dp
    // Initialize dp[u] with INF before filling
    fill(dp[u].begin(), dp[u].end(), INF);

    // Case 1: u does not cultivate (K_u = 0). Cost is 0, production is 0.
    dp[u][0] = 0;

    // Case 2: u cultivates k > 0 fields.
    for (int k = 1; k <= Q[u-1]; ++k) {
        long long prod_u = (long long)k * W[u-1];
        long long cost_u = (long long)k * k * C[u-1];

        for (int p_child = 0; p_child <= S; ++p_child) {
            if (dp_children[p_child] != INF) {
                long long current_prod = prod_u + p_child;
                long long next_prod_idx = min((long long)S, current_prod);
                dp[u][next_prod_idx] = min(dp[u][next_prod_idx], cost_u + dp_children[p_child]);
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;

    Q.resize(N);
    W.resize(N);
    C.resize(N);
    adj.resize(N + 1);
    children.resize(N + 1);
    dp.assign(N + 1, vector<long long>(S + 1, INF));

    for (int i = 0; i < N; ++i) {
        cin >> Q[i] >> W[i] >> C[i];
    }

    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Build a directed tree from the undirected graph
    build_tree_dfs(1, 0);

    // Solve the DP on the tree
    solve_dfs(1);
    
    long long min_cost = dp[1][S];

    if (min_cost == INF) {
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }

    return 0;
}