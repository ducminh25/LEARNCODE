#include <bits/stdc++.h>
using namespace std;

int cha[100001] = {0};
int n, m, s, f;
vector<int> a[100005];
int r = -1, maxx;
int d = 0, res[100005], t[100005];
void truyvet(int f, int s) {
    d = 0;
    while (f != (n + 1)) {
        d++;
        res[d] = f; // cha[p];
        f = cha[f];
    }
}

bool bfs(int x) {
    queue<int> q;
    int u, v;
    for (int i = 1; i <= n; i++) cha[i] = 0;
    cha[s] = n + 1;
    q.push(s);
    while (!q.empty()) {
        u = q.front();
        q.pop();
        // cout<<u<<" ";
        for (int i = 0; i < a[u].size(); i++) {
            v = a[u][i];
            // cout<<u<<" "<<v<<endl;
            if (cha[v] == 0 && abs(t[u] - t[v]) <= x) {
                cha[v] = u;
                if (v == f) {
                    r = x;
                    truyvet(f, s);
                    return true;
                } else
                    q.push(v);
            }
        }
    }
    //  cout<<endl;
    return false;
}
void nhap() {
    scanf("%d %d %d", &n, &s, &f);
    maxx = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &t[i]);
        if (t[i] > maxx) maxx = t[i];
    }
    int u, v;
    while (cin >> u >> v)
    // for(int i=1; i<=m; i++)
    {
        m++;
        // scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    // cout<<m<<endl;
}

void bs(int l, int r) {
    while (l <= r) {
        //  cout<<l<<" "<<r<<endl;
        int mid = (l + r) / 2;
        if (bfs(mid) == true) {
            r = mid - 1;
        } else
            l = mid + 1;
    }
}

int main() {
    // freopen("move.inp", "r", stdin);
    // freopen("move.out", "w", stdout);
    nhap();
    // if(bfs(2)==true) cout<<"co";
    // cout<<bfs(2)<<endl;
    // cout<<r;
    bs(1, maxx);
    cout << r << endl;
    if (r != -1) {
        // cout<<d<<endl;
        for (int i = d; i >= 1; i--) printf("%d ", res[i]);
    }
}
