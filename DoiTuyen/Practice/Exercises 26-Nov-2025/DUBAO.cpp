#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
int n, a[N], D[N];             // D là mảng Difference / Coverage
vector<pair<int, int>> spells; // Lưu {vị trí bắt đầu, độ dài}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int max_len = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            int j = i;
            while (j <= n && a[j] < 0) j++;
            int len = j - i;
            spells.push_back({i, len});
            max_len = max(max_len, len);
            i = j - 1;
        }
    }

    // Bước 1: Sweep-line cơ bản cho quy tắc 2T
    for (auto p : spells) {
        int L = max(1, p.first - 2 * p.second);
        int R = p.first - 1;
        if (L <= R) {
            D[L]++;
            D[R + 1]--;
        }
    }

    // Bước 2: Prefix sum để lấy trạng thái phủ
    int ans = 0, cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += D[i];
        D[i] = cur; // Lưu lại trạng thái: >0 là đã được dự báo
        if (D[i] > 0) ans++;
    }

    // Bước 3: Tham lam tìm lợi nhuận từ quy tắc 3T
    int max_gain = 0;
    for (auto p : spells) {
        if (p.second == max_len) {
            int gain = 0;
            // Vùng mở rộng thêm: [Start - 3T, Start - 2T - 1]
            int L = max(1, p.first - 3 * p.second);
            int R = p.first - 2 * p.second - 1;
            for (int k = L; k <= R; ++k)
                if (D[k] == 0) gain++; // Chỉ đếm những ngày chưa được phủ
            max_gain = max(max_gain, gain);
        }
    }

    cout << ans + max_gain;
    return 0;
}