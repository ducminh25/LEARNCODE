#include <bits/stdc++.h>
using namespace std;
int d, m, y;
int month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int day, year;

void input() {
    cin >> d >> m >> y;
}

void solve() {
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) month[2] = 29;
    day = month[m];
    if (d == day) {
        d = 1;
        m++;
        if (m == 13) {
            m = 1;
            y++;
        }
    }
    else d++;
    cout << d << " " << m << " " << y;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU1.inp", "r")) {
        freopen("CAU1.inp", "r", stdin);
        freopen("CAU1.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}


/*
Thầy giáo tập trung ôn luyện củng cố kiến thức cho đội tuyển học sinh giỏi dự thi cấp tỉnh. Thầy giao bài tập theo từng chủ đề. Trong phần bài tập rẽ nhánh có câu hỏi mà cả nhóm chưa đưa ra được lời giải, bạn hãy giúp các bạn trong nhóm giải bài toán sau: Giả sử hôm nay là ngày d tháng t năm n. Hỏi ngày mai là ngày một?
Dữ liệu vào: gồm 3 số nguyên d, t, n cách nhau một khoảng trắng biểu thị cho ngày, tháng, năm (1 ≤ d ≤ 31, 1 ≤ t ≤ 12, 1 ≤ n ≤ 9999). 
Biết: Dữ liệu cho đảm bảo là một ngày hợp lệ (Ví dụ ngày không hợp lệ: 31 2 2014).
Kết quả: gồm 3 số lần lượt là ngày, tháng, năm của ngày tiếp theo, mỗi số cách nhau một khoảng trắng. Không in số 0 ở đầu ngày và tháng.
- Cần chú ý năm nhuận tháng 2 có 29 ngày, năm nhuận là: (năm chia hết cho 400) hoặc (chia hết cho 4 và không chia hết cho 100)
*/