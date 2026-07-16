#include <bits/stdc++.h>
using namespace std;
int cha[100001] = {0};
int n, m, s, f, d = 0, k, p[100005];
vector<int> a[100005];
vector<int> res;

void truyvet(int f, int s) {
    int r[10005], d = 0;
    while (f != s) {
        d++;
        r[d] = f;
        f = cha[f];
    }
    for (int i = d; i >= 1; i--)
        res.push_back(r[i]); // cha[p];

    // cout<<endl;
}

void bfs(int s, int f) {
    // cout<<s<<" - "<<f<<endl;
    queue<int> q;
    for (int i = 1; i <= n; i++) cha[i] = 0;
    cha[s] = n + 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        // cout<<u<<" ";
        for (int i = 0; i < a[u].size(); i++) {
            int v = a[u][i];
            if (cha[v] == 0) {
                cha[v] = u;
                if (v == f) {
                    truyvet(f, s);
                    return;
                } else
                    q.push(v);
            }
        }
    }
}
void nhap() {
    scanf("%d %d %d", &n, &k, &m);
    scanf("%d", &s);
    for (int i = 1; i <= k; i++) scanf("%d", &p[i]);
    int x, y;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void giai() {
    p[0] = s;
    p[k + 1] = s;
    // cout<<p[k]<<" "<<p[k+1];
    // bfs(p[k],p[k+1]);

    for (int i = 0; i <= k; i++) bfs(p[i], p[i + 1]);
    cout << res.size() << endl;
    cout << s << " ";
    for (int i = 0; i <= res.size() - 1; i++)
        cout << res[i] << " ";
    // printf("%d ",res[i]);
}
int main() {
    // freopen("tour.inp","r",stdin);
    // freopen("tour.out","w",stdout);
    nhap();
    giai();
}


// Olympic 30/4 2010