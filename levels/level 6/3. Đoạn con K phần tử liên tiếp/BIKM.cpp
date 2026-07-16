#include <bits/stdc++.h>
using namespace std;

const int MAX_COLOR = 1000001; // Xác định giới hạn màu là 10^6 + 1

int last_position[MAX_COLOR]; // Khai báo mảng toàn cục để tránh tràn stack

int main() {
    ios_base::sync_with_stdio(false); // Tăng tốc độ đọc nhập dữ liệu
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    // Khởi tạo mảng last_position bằng -1
    for (int i = 0; i < MAX_COLOR; ++i) {
        last_position[i] = -1;
    }

    int color;
    int max_color = -1;

    for (int i = 0; i < N; ++i) {
        cin >> color;

        // Kiểm tra và cập nhật max_color nếu viên bi hiện tại gây "chướng mắt"
        if (last_position[color] != -1 && i - last_position[color] <= K) {
            max_color = max(max_color, color);
        }

        // Cập nhật vị trí cuối cùng của màu hiện tại
        last_position[color] = i;
    }

    cout << max_color << endl;

    return 0;
}