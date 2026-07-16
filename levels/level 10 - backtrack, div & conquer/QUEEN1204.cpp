/*
Bài 3. QUEEN1204 Quân hậu
Trên bàn cờ tổng quát kích thước m x n người ta ghi vào mỗi ô (i, j) một số nguyên a_ij. 
Hãy tìm cách đặt một quân hậu vào đúng 1 ô trên bàn cờ sao cho tổng các số ghi trên các ô bị quân hậu đó khống chế là lớn nhất. 
(Quân hậu khống chế tất cả các ô trên cùng hàng, cùng cột hoặc cùng đường chéo, tính cả ô nó đang đứng)
Input
· Dòng 1 ghi hai số nguyên m, n (1 ≤ m, n ≤ 1000)
· m dòng tiếp theo, dòng thứ i chứa n số nguyên, số thứ j là a_ij (|a_ij| ≤ 10^6)
Output: ghi tổng các số trên các ô bị quân hậu khống chế theo phương án đặt hậu tìm được.
Ví dụ:

Input
4 4
1 1 2 2
3 3 4 4
5 5 6 6
7 7 8 8

Output
59

Tóm tắt đề:
Cho 1 bàn cờ vua. Tìm ô đặt quân hậu sao cho tổng của các ô mà nó ăn được là lớn nhất.
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[1001][1001];
long long ngang[10001];
long long doc[10001];
long long cheoPT[10001];
long long cheoTP[10001];

void read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

void tinh() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ngang[j] += a[i][j];
            doc[i] += a[i][j];
            cheoTP[i - j + 1000] += a[i][j];
            cheoPT[i + j] += a[i][j];
        }
    }
}

void solve() {
    tinh();
    long long maxx = LLONG_MIN;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum = ngang[j] + doc[i] + cheoTP[i - j + 1000] + cheoPT[i + j] - (3 * a[i][j]);
            maxx = max(maxx, sum);
        }
    }
    cout << maxx << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    read();
    solve();
    return 0;
}