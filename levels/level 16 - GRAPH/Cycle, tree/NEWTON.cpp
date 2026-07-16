#include <bits/stdc++.h>
using namespace std;
int vism[100005], visc[100005], del[100001];
int n, mm, mc, pm, pc;
vector<int> a[100005], b[100005];
int k = 0, q[100005];

void truyvet(int f) {
    k = 0;
    while (f != n + 1) {
        k++;
        q[k] = f; // vis[p];
        f = visc[f];
    }
}

void dfs_meo(int u) {
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (vism[v] == 0) {
            vism[v] = u;
            dfs_meo(v);
        }
    }
}
void dfs_ct(int u) {
    for (int i = 0; i < b[u].size(); i++) {
        int v = b[u][i];
        if (v == pc) {
            truyvet(u);
            if (k > 2) return;
        }
    }
    for (int i = 0; i < b[u].size(); i++) {
        if (k > 2) return;
        int v = b[u][i];

        if (del[v] == 0 && visc[v] == 0) {
            visc[v] = u;
            dfs_ct(v);
        }
    }
}
void dfs_chuot(int u) {
    for (int i = 0; i < b[u].size(); i++) {
        int v = b[u][i];
        if (visc[v] == 0) {
            visc[v] = u;
            dfs_chuot(v);
        }
    }
}
void input() {
    cin >> n >> pm >> pc;
    cin >> mm;
    int x, y;
    for (int i = 1; i <= mm; i++) {
        cin >> x >> y;
        a[x].push_back(y);
        // a[y].push_back(x);
    }
    cin >> mc;
    for (int i = 1; i <= mc; i++) {
        cin >> x >> y;
        b[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        sort(b[i].begin(), b[i].end());
}
void solve() {
    vism[pm] = n + 1;
    dfs_meo(pm);
    visc[pc] = n + 1;
    dfs_chuot(pc);
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        // cout<<vism[i]<<" "<<visc[i]<<endl;
        if (vism[i] > 0 && visc[i] > 0) {
            res.push_back(i);
            // cout<<i<<endl;
            del[i] = 1;
        }
    }
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    // cout<<endl;
    for (int i = 1; i <= n; i++) visc[i] = 0;

    visc[pc] = n + 1;
    dfs_ct(pc);
    if (k > 2) {
        cout << k << endl;
        for (int i = k; i >= 1; i--) cout << q[i] << endl;
        // cout<<pc<<" ";
    } else
        cout << 0 << endl;
}
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // freopen("newton.inp", "r", stdin);
    // freopen("newton.out", "w", stdout);
    input();
    solve();

    return 0;
}

/*
Trong toà nhà của Newton gồm N phòng đánh số từ 1 đến N, có một con mèo và một con chuột, mỗi con chiếm một phòng riêng làm nhà của mình, mèo phòng pm, chuột phòng pc, không có cửa từ phòng pm sang phòng pc.
Với hai phòng A và B bất kỳ, từ A sang B, có thể có/không có cửa, nhưng nếu có, Newton quy định rất rõ cửa là của mèo hay của chuột, nếu là của mèo/chuột thì chuột/mèo không được đi.
Từ A sang B có thể có cả hai loại cửa hoặc chỉ có một loại cửa cho một trong hai con hoặc không có cửa, các cửa đều chỉ đi một chiều, cửa từ phòng A sang phòng B chỉ có thể đi được từ A sang B.
Hãy trả lời cho chuột hai vấn đề sau (ai trả lời tốt nhất thì họ hàng chuột không bao giờ đến nhà quấy nhiễu):
1. Trong quá trình dạo chơi trong nhà, tại những phòng nào chuột có thể gặp mèo (các cuộc dạo chơi của cả hai con đều xuất phát từ nhà của mình).
2. Có hay không hành trình của chuột qua ít nhất hai phòng khác nhau từ nhà nó và quay về nhà nó sao cho trên hành trình không bao giờ gặp mèo. Nếu có, hãy ghi ra các đỉnh thuộc hành trình đó.

Input
• Dòng thứ nhất ghi ba số n, pm, pc (N <= 100).
• Dòng thứ hai ghi số mm là số cửa mèo có thể đi qua.
• mm dòng tiếp theo, mỗi dòng ghi hai số A, B cho biết có cửa cho mèo (một chiều) từ phòng A sang phòng B.
• Dòng tiếp theo ghi số mc là số cửa chuột có thể đi qua.
• mc dòng tiếp theo, mỗi dòng ghi hai số A, B cho biết có cửa cho chuột (một chiều) từ phòng A sang phòng B.

Output
• Dòng thứ nhất ghi số NH là số phòng mà chuột có thể gặp mèo,
• Nếu NH > 0, tiếp theo là NH dòng, mỗi dòng ghi số hiệu một phòng; theo thứ tự tăng dần.
• Sau đó là một dòng ghi số AT là số phòng khác nhau trên hành trình theo yêu cầu ở phần 2, nếu không có thì ghi số 0;
• Nếu có, trong AT dòng tiếp theo, mỗi dòng ghi số hiệu một phòng theo thứ tự trên hành trình bắt đầu từ nhà của chuột.
Nếu có nhiều hành trình thỏa đề thì xuất hành trình có thứ tự từ điển nhỏ nhất.

Ví dụ:
INPUT:
5 2 4
2
1 2
2 1
10
1 3
2 5
3 4
4 2
4 5
5 4
5 3
5 1
4 3
3 5
--> OUTPUT:
2
1
2
3
4
3
5
*/