#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 50005;

struct Robot {
    long long w;
    long long x;
    int d;
};

// Khai báo mảng toàn cục cho tập dữ liệu lớn
Robot robots[MAX_N];
int n;
long long L;

long long t0_times[MAX_N], t1_times[MAX_N];
int k0 = 0, k1 = 0;

long long neg_x[MAX_N];
int neg_count = 0;

pair<long long, long long> events[MAX_N];

// Sắp xếp các robot theo tọa độ tăng dần
bool compareRobot(const Robot& a, const Robot& b) {
    return a.x < b.x;
}

void input() {
    cin >> n >> L;
    for (int i = 0; i < n; ++i) {
        cin >> robots[i].w >> robots[i].x >> robots[i].d;
    }
}

void solve() {
    long long total_w = 0;
    for (int i = 0; i < n; ++i) {
        total_w += robots[i].w;
    }

    // Sắp xếp robot theo vị trí không gian ban đầu
    sort(robots, robots + n, compareRobot);

    // Tính các khoảng thời gian chạm biên nếu xem như đi xuyên nhau
    for (int i = 0; i < n; ++i) {
        if (robots[i].d == -1) {
            t0_times[k0++] = robots[i].x;
            neg_x[neg_count++] = robots[i].x;
        } else {
            t1_times[k1++] = L - robots[i].x;
        }
    }

    // Sắp xếp thời gian đi tới các biên
    sort(t0_times, t0_times + k0);
    sort(t1_times, t1_times + k1);

    // Gắn thời gian cho K robot đứng bên trái (sẽ tới 0) 
    // và N-K robot đứng bên phải (sẽ tới L)
    for (int i = 0; i < k0; ++i) {
        events[i] = {t0_times[i], robots[i].w};
    }
    for (int i = 0; i < k1; ++i) {
        events[k0 + i] = {t1_times[i], robots[k0 + i].w};
    }

    // Sắp xếp tổng thể các sự kiện rơi theo thứ tự thời gian
    sort(events, events + n);

    long long target_w = (total_w + 1) / 2; // Tối thiểu là một nửa tổng trọng lượng (làm tròn lên)
    long long current_w = 0;
    long long t = -1;
    
    // Quét mảng sự kiện để tìm thời điểm T
    for (int i = 0; i < n; ++i) {
        current_w += events[i].second;
        if (current_w >= target_w) {
            t = events[i].first;
            break;
        }
    }

    // Đếm số lần gặp nhau (đảo chiều) trong thời gian T bằng Binary Search
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (robots[i].d == 1) {
            long long current_x = robots[i].x;
            // Tìm số lượng robot có hướng -1 thoả mãn khoảng cách x_j - x_i <= 2*T
            int left_idx = upper_bound(neg_x, neg_x + neg_count, current_x) - neg_x;
            int right_idx = upper_bound(neg_x, neg_x + neg_count, current_x + 2 * t) - neg_x;
            ans += (right_idx - left_idx);
        }
    }

    // In kết quả
    cout << ans << "\n";
}

int main() {
    ios_base :: sync_with_stdio (false); cin.tie (0); cout.tie (0);
    
    // Mở file vào ra theo đề bài quy định
    if (fopen("ROBOT.INP", "r")) {
        freopen("ROBOT.INP", "r", stdin);
        freopen("ROBOT.OUT", "w", stdout);
    }
    
    input();
    solve();
    
    return 0;
}
