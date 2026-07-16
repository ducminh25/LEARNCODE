#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, d, k, x[maxn], a[maxn], cnt = 0, s = 0;
bool ok;

void input() {
    cin >> n >> k;
}

void findDiv() {
    d = 1; a[d] = k;
    for (int i = 2; i <= (int) sqrt(k); i++) {
        if (k % i == 0) {
            d++; a[d] = i;
            d++; a[d] = k / i;
        }
    }
    if (sqrt(k) == int(sqrt(k))) d--;
}

void output(int p) {
    if (ok) return;
    for (int i = 1; i <= p; ++i) 
        if (x[i] > 0) cnt++;
    cout << cnt << endl;
    for (int i = 1; i <= p; ++i) {
        if (x[i] > 0) cout << a[i] << ' ' << x[i] << endl;
    }
}

void vet(int i) {
    if (ok) return;
    for (int j = 0; j <= (n - s) / a[i]; ++j) {
        x[i] = j;
        s += j * a[i];
        if (i == d || s >= n) {
            if (s == n) {
                output(i);
                ok = true;
            }
        }
        else vet(i + 1);
        s -= j * a[i];
    }
}

int main() {
    if(fopen("phantich.inp", "r")) {
        freopen("phantich.inp", "r", stdin);
        freopen("phantich.out", "w", stdout);
    }
    input();
    findDiv();
    ok = false;
    vet(1);
    if (!ok) cout << 0;

    return 0;
}


/*
Cho hai số nguyên dương N và K (1<K<N). 
Hãy phân tích N thành tổng của các ước khác 1 của K.

Ví dụ: Với N = 10 và K = 6, ta có các cách phân tích số N như sau:

10 = 6 + 2 + 2
10 = 3 + 3 + 2 + 2
10 = 2 + 2 + 2 + 2 + 2 

Còn với N=5 và K=2 ta không phân tích được.

Input
Gồm 2 số N và K. (1 < K < N <= 200)

Output
Nếu không phân tích được thì ghi số 0. Nếu phân tích được thì:
Dòng đầu ghi số T là số lượng số hạng.
T dòng sau, Mỗi dòng gồm 2 số nguyên lần lượt là số hạng và số lần xuất hiện của số hạng đó trong biểu thức phân tích.
Nếu có nhiều cách phân tích thì chỉ ghi một cách trong số các cách đó.
*/