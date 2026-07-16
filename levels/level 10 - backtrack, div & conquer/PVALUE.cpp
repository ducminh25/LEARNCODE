#include <bits/stdc++.h>
using namespace std;
const int m = 1e9 + 7; // MOD
int n, a[1000005];

long long powmod(long long a, long long n) {
    if (n == 0) return 1;
    long long tmp = powmod(a, n / 2);
    tmp = ((tmp % m) * (tmp % m)) % m;
    if (n % 2 == 0) return tmp;
    else return ((tmp % m) * (a % m)) % m;
}

long long gcd(long long a, long long b) {
    long long tmp;
    while (b > 0) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
}

void solve() {
    long long f = 1;
    for (int i = 1; i <= n; ++i) f = ((f % m) * (a[i] % m)) % m;
    long long g = a[1];
    for (int i = 2; i <= n; ++i) g = gcd(g, a[i]);
    cout << powmod(f, g) << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}



/*
Bài 3. PVALUE Giá trị hoàn hảo
Cho một mảng A gồm N số nguyên, từ mảng A, hai hàm FN và G của mảng A được tính như sau:
F[N] = A1 * A2 * ... * AN
G[N]= GCD(A1,A2 .. ,AN)
Từ hai hàm trên, ta định nghĩa giá trị hoàn hảo của mảng A bằng P[N] = F[N]^G[N].
Yêu cầu: cho mảng A, hãy tính giá trị PN. Giá trị PN có thể rất lớn, vì vậy chỉ cần xuất ra phần dư của nó khi chia cho 1000000007 (10^9 + 7). 1e9 + 7
Input
· Dòng đầu tiên chứa số nguyên dương N - số lượng phần tử của mảng (N <= 10^5).
· Dòng thứ hai chứa N số nguyên dương là giá trị các phần tử trong mảng A, các phần tử có giá trị không vượt quá 10^9.
Output: Một số nguyên duy nhất là kết quả cần tìm.
Ví dụ:

Input

Output

2
26

3
3 5 15

144

225
*/