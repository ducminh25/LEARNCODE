#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n); // pair<int, int> để lưu giá trị độ ấn tượng và chỉ số gốc

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1; // lưu chỉ số gốc
    }

    sort(a.begin(), a.end()); // sắp xếp theo giá trị độ ấn tượng

    int min_diff = INT_MAX;
    int idx = 0;

    // tìm bộ 4 phần tử có độ chênh lệch nhỏ nhất
    for (int i = 0; i <= n - 4; i++) {
        int current_diff = a[i + 3].first - a[i].first;
        if (current_diff < min_diff) {
            min_diff = current_diff;
            idx = i;
        }
    }

    // xuất kết quả
    cout << min_diff << endl;
    for (int i = idx; i < idx + 4; i++) {
        cout << a[i].second << " ";
    }
    cout << endl;

    return 0;
}