#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k, q;
    if (!(cin >> n >> k >> q)) return;

    // Mảng đánh dấu loại ràng buộc tại mỗi vị trí
    vector<int> is_min(n + 1, 0);
    vector<int> is_mex(n + 1, 0);

    for (int i = 0; i < q; ++i) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 1) { 
            // Ràng buộc Min: Range [l, r] phải >= k
            for (int j = l; j <= r; ++j) is_min[j] = 1;
        } else { 
            // Ràng buộc Mex: Range [l, r] có MEX = k
            for (int j = l; j <= r; ++j) is_mex[j] = 1;
        }
    }

    vector<int> a(n + 1);
    int mex_cnt = 0; // Biến đếm riêng cho các ô chỉ thuộc MEX

    for (int i = 1; i <= n; ++i) {
        if (is_min[i] && is_mex[i]) {
            // Loại 1: Vừa Min, vừa Mex
            // Phải >= k (do Min) và != k (do Mex) -> Chọn k + 1
            a[i] = k + 1;
        } 
        else if (is_min[i]) {
            // Loại 2: Chỉ Min
            // Phải >= k -> Chọn k
            a[i] = k;
        } 
        else if (is_mex[i]) {
            // Loại 3: Chỉ Mex
            // Phải điền các số 0..k-1 để thỏa mãn Mex
            // Dùng biến đếm xoay vòng để rải đều các số
            a[i] = mex_cnt % k;
            mex_cnt++;
        } 
        else {
            // Loại 4: Tự do -> Chọn 0
            a[i] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << a[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t)
        while (t--) solve();
        
    return 0;
}