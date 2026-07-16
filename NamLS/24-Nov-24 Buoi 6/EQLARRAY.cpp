#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        sum += b[i];
    }

    if (sum % k != 0) {
        cout << "NO\n";
        return;
    }
    int maxx = *max_element(b.begin(), b.end());
    if (maxx > sum / k) {
        cout << "NO\n";
        return;
    }
    
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    if(fopen("EQLARRAY.INP", "r")) {
        freopen("EQLARRAY.INP", "r", stdin);
        freopen("EQLARRAY.OUT", "w", stdout);
    }
    
    int Q;
    cin >> Q;
    while (Q--) {
        solve();
    }
    
    return 0;
}

/*
Cho hai dãy nguyên a, b đều gồm n phần tử. Ban đầu tất cả phần tử của dãy a đều bằng 0.
Bạn cần biến dãy a thành dãy b bằng cách thực hiện một số lần thao tác sau: chọn ra k phần tử của dãy a và tăng mỗi phần tử thêm 1 đơn vị.
Kiểm tra xem có thể biến dãy a thành dãy b được hay không?
*/