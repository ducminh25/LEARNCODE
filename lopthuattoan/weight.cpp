#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
long long resmax, resmin;
int n;
long long a[maxn], lmin[maxn], rmin[maxn], lmax[maxn], rmax[maxn];
stack<int> st;
void nhap() {
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d ", &a[i]);
}
void khoi_tao_st() {
    while (!st.empty()) st.pop();
}

void tinh_left_min() {
    khoi_tao_st();
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        if (st.empty())
            lmin[i] = 1;
        else
            lmin[i] = st.top() + 1;

        st.push(i);
    }
}
void tinh_right_min() {
    khoi_tao_st();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] > a[i])
            st.pop();
        if (st.empty())
            rmin[i] = n;
        else
            rmin[i] = st.top() - 1;
        st.push(i);
    }
}
void tinh_left_max() {
    khoi_tao_st();
    for (int i = 1; i <= n; i++) {
        while (!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        if (st.empty())
            lmax[i] = 1;
        else
            lmax[i] = st.top() + 1;

        st.push(i);
    }
}
void tinh_right_max() {
    khoi_tao_st();
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && a[st.top()] < a[i])
            st.pop();
        if (st.empty())
            rmax[i] = n;
        else
            rmax[i] = st.top() - 1;
        st.push(i);
    }
}

void giai() {
    tinh_left_min();

    tinh_right_min();
    tinh_left_max();
    tinh_right_max();

    for (int i = 1; i <= n; i++) {
        resmin = resmin + a[i] * (i - lmin[i] + 1) * (rmin[i] - i + 1);
        resmax = resmax + a[i] * (i - lmax[i] + 1) * (rmax[i] - i + 1);
    }
    cout << (resmax - resmin);
}
int main() {
    // freopen("weight.inp","r",stdin);
    // freopen("weight.out","w",stdout);
    nhap();
    giai();
}

/*
Trọng số khoảng
Định nghĩa trọng số của một dãy số nguyên là độ chênh lệch giữa phần tử lớn nhất và phần tử nhỏ nhất trong dãy.
Ví dụ trọng số của dãy (3,1,7,2) là 6, trọng số của dãy (40, 40) là 0.
Yêu cầu: Cho dãy số nguyên A = (a1, a2, ... , an). Hãy tính tổng trọng số của tất cả các dãy con gồm các phần tử liên tiếp trong A.
Ví dụ với A = (1,2,3), những dãy con gồm các phần tử liên tiếp trong A là:
· Dãy rỗng và các dãy (1), (2), (3): trọng số 0
· Dãy (1,2) và dãy (2,3): trọng số 1
· Dãy (1,2,3): trọng số 2. Tổng trọng số cần tìm: 4

Input
· Dòng 1 chứa số nguyên dương n <= 10^6
· Dòng 2 chứa n số nguyên dương a1, a2, ..., an. Các số có giá trị không vượt quá 10^6. Các số trên một dòng của input file được ghi cách nhau ít nhất một dấu cách.

Output: Ghi một số nguyên duy nhất là kết quả tìm tìm được.

Ví dụ:
INPUT: 3 \n 1 2 3
OUTPUT: 4

INPUT: 5 \n 4 3 1 7 2
OUTPUT: 47
*/