#include <bits/stdc++.h>
using namespace std;
int m, n;
vector<int> cnt(10, 0);

void input() {
    cin >> m >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        cnt[x]++;
        if (y != 0) cnt[y]++;
    }
}

void solve() {
    for (int i = 1; i <= 9; ++i) {
        double ratio = (double)cnt[i] / m;
        cout << fixed << setprecision(1) << ratio << " ";
    }
    cout << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("TLCHOI.inp", "r")) {
        freopen("TLCHOI.inp", "r", stdin);
        freopen("TLCHOI.out", "w", stdout);
    }
    input();
    solve();

    return 0;
}

/*
Trong kỳ thi tuyển sinh vào lớp 10 năm học 2024-2025 của trường THPT chuyên Lam Sơn có tuyển sinh 9 môn chuyên: Toán, Vật lí, Hóa học, Sinh học, Tin học, Ngữ văn, Lịch sử, Địa lí, Tiếng Anh được ký hiệu lần lượt từ 1 đến 9.
Có tất cả N thí sinh đăng ký dự thi, mỗi thí sinh được đăng ký dự thi một hoặc hai môn chuyên gọi là môn chuyên 1 (bắt buộc) và môn chuyên 2 (tự chọn, ghi 0 nếu không đăng ký). Tất cả 9 môn chuyên đều có chỉ tiêu tuyển sinh bằng nhau là M học sinh mỗi môn. Gọi tỉ lệ chọi của mỗi môn là tổng số thí sinh dự thi của môn đó chia cho chỉ tiêu (M).

Yêu cầu: Hãy tính tỉ lệ chọi của từng môn.

Input
Vào từ file văn bản TLCHOI.INP gồm:

• Dòng đầu tiên chứa số 2 số nguyên dương M (1<M<50) và N (1<N<2000).

• Dòng thứ 2 chứa N cặp số nguyên (N*2 số nguyên, các số phân biệt bằng dấu cách), mỗi cặp gồm 2 số x, y là đăng kí dự thi của mỗi thí sinh (x thuộc [1,9] là ký hiệu môn chuyên 1 (bắt buộc), y thuộc [0,9] là ký hiệu môn chuyên 2 (tự chọn, nếu học sinh không đăng ký thì môn 2 ghi 0)).

Output
Ghi ra File văn bản TLCHOI.OUT gồm một dòng duy nhất ghi 9 số thực là tỉ lệ chọi của 9 môn thi (các số làm tròn đến 1 chữ số sau dấu thập phân và cách nhau một dấu cách theo thứ tự từ môn 1 đến 9).
*/