#include <bits/stdc++.h>
using namespace std;

vector<int> a[3005];
int n, d = 0;
int cha[3005], kc[3005];
bool ok = false, ct[3005];

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
}

void truyvet(int u, int v) {
    // cout<<"vao";
    while (u != v) {
        // cout<<u<<endl;
        ct[u] = true;
        u = cha[u];
        // if(u==0) break;
    }
    ct[v] = true;
}
void dfs_ct(int u) {
    for (int i = 0; i < a[u].size(); i++) {
        if (ok == true) return;
        int v = a[u][i];
        if (cha[v] > 0 && v != cha[u]) {
            truyvet(u, v);
            // cout<<u<<" "<<v<<" "<<cha[u]<<" "<<cha[2]<<endl;
            ok = true;
            return;
        }
        if (cha[v] == 0) {
            cha[v] = u;
            dfs_ct(v);
        }
    }
}

void gom_ct() {
    for (int i = 1; i <= n; i++) {
        if (ct[i] == true) {
            for (int j = 0; j < a[i].size(); j++) {
                int v = a[i][j];
                if (ct[v] == false) {
                    a[n + 1].push_back(v);
                    a[v].push_back(n + 1);
                }
            }
        }
    }
}

int res = 0;

void dfs_kc(int u) {
    d++; // cout<<u<<" "<<d<<endl;
    kc[u] = d;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (kc[v] == 0 && ct[v] == false)
            dfs_kc(v);
    }
    d--;
}

void giai() {
    cha[1] = n + 2;
    dfs_ct(1);
    gom_ct();
    d = -1;
    //  for(int i=0;i<a[7].size();i++)
    // cout<<a[7][i]<<" ";
    //  cout<<endl;
    ct[n + 1] = true;
    dfs_kc(n + 1);
    int maxx = 0;
    for (int i = 1; i <= n; i++) {
        if (ct[i] == false && kc[i] > maxx)  maxx = kc[i];
            // cout << kc[i] << ' ';
    }
    cout << maxx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("TRAM.inp", "r", stdin);
    // freopen("TRAM.out", "w", stdout);
    read();
    giai();
}

/*
Hệ thống tàu điện ngầm của thành phố XYZ gồm n trạm được đánh số từ 1 đến n, kết nối với nhau bởi n đoạn đường ray, mỗi đoạn kết nối đúng hai trạm và không đi qua bất kỳ trạm nào khác. 
Ngoài ra, với hệ thống tàu điện ngầm này, người ta có thể đi từ một trạm đến một trạm khác bất kì dọc theo các đoạn đường ray. 
Các đoạn này có thể được sử dụng để di chuyển theo cả hai hướng. Giữa hai trạm không có nhiều hơn một đoạn đường ray.

Hệ thống tàu điện ngầm này có đúng một “chu trình”. “Chu trình” là một tập các trạm phân biệt p1,p2,..,pk mà 2 trạm pi và pi+1 có đoạn đường ray nối với nhau, đoạn pk và p1 có đoạn đường ray nối với nhau.

Yêu cầu: xác định khoảng cách (theo số đoạn đường ray) từ “chu trình” đến trạm xa nó nhất.

Input
- Dòng đầu tiên chứa số nguyên n(3≤n≤3000)
- n dòng sau: mô tả của các đoạn đường ray. Mỗi dòng chứa một cặp số nguyên xi,yi(1≤xi,yi≤n) biểu diễn đoạn đường từ trạm xi trạm yi

Output
In khoảng cách từ “chu trình” đến trạm xa nó nhất (theo số đoạn đường ray). Nếu tất cả các trạm đều nằm trong “chu trình”, xuất khoảng cách xa nhất là 0.

Tóm tắt
Cho đồ thị là liên thông và có đúng một chu trình. Tính khoảng cách (theo số cạnh), từ tất cả các đỉnh đến chu trình (in 0 cho đỉnh trong chu trình).
*/