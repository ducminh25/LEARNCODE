#include <bits/stdc++.h>
using namespace std;

int m, n, res, maxx;
int x[1001][1001], a[30010], l[30010], r[30010], p[30010];
stack<int> st;
void nhap() {
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> x[i][j];
}
void khoi_tao_st() {
    while (!st.empty()) st.pop();
}

void tinh_left() {
    khoi_tao_st();
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (st.empty())
            l[i] = 1;
        else
            l[i] = st.top() + 1;

        st.push(i);
    }
}
void tinh_right() {
    khoi_tao_st();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] >= a[i])
            st.pop();
        if (st.empty())
            r[i] = n;
        else
            r[i] = st.top() - 1;

        st.push(i);
    }
}

void tim_hcn() {
    tinh_left();
    tinh_right();
    p[1] = a[1] * (r[1] - l[1] + 1);
    maxx = 1;
    for (int i = 2; i <= n; i++) {
        p[i] = a[i] * (r[i] - l[i] + 1);
        if (p[i] > p[maxx]) maxx = i;
    }
    // printf("%d %d %d\n",p[maxx], l[maxx], r[maxx]);
}
void giai() {
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++)
            if (x[i][j] == 9)
                a[j] = a[j] + 1;
            else
                a[j] = 0;
        tim_hcn();
        if (p[maxx] > res) res = p[maxx];
    }
    cout << res;
}
int main() {
    nhap();

    giai();
    return 0;
}

/*
Hình chữ nhật số 9 lớn nhất rect9.cpp
Cho trước một lưới hình chữ nhật kích thước m x n. Trong mỗi ô lưới ghi một số nguyên thuộc đoạn [0,9].
Yêu cầu: Tìm diện tích lớn nhất của hình chữ nhật con chỉ chứa các ô lưới ghi số 9.
Input:
· Dòng đầu tiên ghi 2 số nguyên dương m, n cho biết số dòng và số cột của lưới (2 <= m, n <= 1000).
· Trên m dòng tiếp theo, mỗi dòng ghi n số nguyên thuộc đoạn [0, 9] lần lượt cho biết các giá trị ghi trên ô lưới tương ứng. Các số ghi cách nhau bởi ít nhất một khoảng trắng.
Output: ghi một số nguyên S duy nhất cho biết diện tích lớn nhất của hình chữ nhật cần tìm.

Ví dụ:

Input
6 5
1 2 9 9 3
4 9 9 9 0
7 9 9 9 9
6 9 9 9 9
5 9 9 4 4
1 2 3 0 7

--> OUTPUT: 10
*/