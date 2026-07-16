#include <bits/stdc++.h>
using namespace std;

int cha[100001];
int n;
vector<int> a[100005];
// vector<int> a[100000+1];
int maxx = 0, d;

void dfs(int u) {
    d++;
    if (d > maxx) maxx = d;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (cha[v] == 0) {
            cha[v] = u;
            dfs(v);
        }
    }
    d--;
}
void nhap() {
    // a.clear();
    cin >> n;
    int x;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x == -1) {
            cha[i] = n + 1;
        } else {
            a[x].push_back(i);
        }
    }
}

void giai() {
    for (int i = 1; i <= n; i++) {
        if (cha[i] == n + 1) {
            d = 0;
            dfs(i);
        }
    }
    cout << maxx;
}
int main() {
    // freopen("party.inp","r",stdin);
    // freopen("party.out","w",stdout);
    nhap();
    giai();
}

/*
Tóm tắt
Cho đồ thị dạng rừng (gồm nhiều cây) n đỉnh. Chia các đỉnh thành ít nhóm nhất sao cho trong cùng 1 nhóm không có 2 đỉnh có quan hệ cha, con.
*/