#include <bits/stdc++.h>
using namespace std;
int c, n, s = 0, max1 = 0, a[20], x[100];

void vet(int i) {
    for (int j = x[i - 1] + 1; j <= n; j++) {
        x[i] = j;
        s = s + a[j];
        if (s <= c) {
            if (s >= max1) max1 = s;
            vet(i + 1);
        }
        s = s - a[j];
    }
}

void nhap() {
    cin >> c >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if(fopen("VCOWFLIX.inp", "r")) {
        freopen("VCOWFLIX.inp", "r", stdin);
        freopen("VCOWFLIX.out", "w", stdout);
    }
    nhap();
    x[0] = 0;
    vet(1);
    cout << max1;
}

/*
Cho dãy a gồm n số a1, a2, ..., an. Chọn ra một số các phần tử có tổng lớn nhất mà không vượt quá C.

Nông dân John đang đưa các con bò của anh ta đi xem phim! Xe tải của anh ta thì có sức chứa có hạn thôi, là C kg, anh ta muốn đưa 1 số con bò đi xem phim sao cho tổng khối lượng của đống bò này là lớn nhất, đồng thời xe tải của anh ta vẫn chịu được.
VCOWFLIX.cpp
Cho N con bò và khối lượng W_i của từng con, hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

Input
Dòng 1: 2 số nguyên cách nhau bởi dấu cách: C và N (100 ≤ C ≤ 5000;1 ≤ N ≤ 16)

Dòng 2..N+1: Dòng i+1 chứa 1 số nguyên: W_i (W_i ≤ 10^3)

Output
Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.
*/