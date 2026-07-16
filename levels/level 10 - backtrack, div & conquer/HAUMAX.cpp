#include <bits/stdc++.h>
using namespace std;

int n, x[11], s = 0, res = 0, maxx = 0, a[11][11];
bool c[100], cheo1[100], cheo2[100];

void vet(int i) {
    for (int j = 1; j <= n; j++) {
        if (c[j] == true && cheo1[i - j + (n - 1)] == true && cheo2[i + j] == true) {
            c[j] = false;
            cheo1[i - j + (n - 1)] = false;
            cheo2[i + j] = false;
            s += a[i][j];
            if (i == n) {
                res++;
                if (s > maxx) maxx = s;
            } else vet(i + 1);
            s -= a[i][j];
            c[j] = true;
            cheo1[i - j + (n - 1)] = true;
            cheo2[i + j] = true;
        }
    }
}

void nhap() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
}

void xuli() {
    res = 0;
    for (int i = 0; i <= 2 * n; i++) {
        cheo2[i] = true;
        cheo1[i] = true;
        c[i] = true;
    }
    vet(1);
    cout << maxx;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    nhap();
    xuli();
    return 0;
}


/*
HAUMAX Đặt hậu lớn nhất

Cho bàn cờ vua N*N ô, mỗi ô ghi một số nguyên dương.
Yêu cầu: xếp N quân hậu lên bàn cờ sao cho không quân nào khống chế được quân nào và tổng các số ghi trên các ô mà quân hậu đứng là lớn nhất.
Input:
· Dòng đầu là số nguyên dương N (N ≤ 10)
· N dòng sau, mỗi dòng ghi N số nguyên dương không vượt quá 10^9.
Output: Tổng lớn nhất, nếu không có cách đặt hậu thì xuất 0.
*/