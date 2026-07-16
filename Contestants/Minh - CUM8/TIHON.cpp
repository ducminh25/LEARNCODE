#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;
vector<long long> sum_of_divisors(MAXN, 1);
bitset<MAXN> is_tiny;

void sieve() {
    for (int i = 2; i < MAXN; i++) {
        if (sum_of_divisors[i] == 1) {
            for (int j = i; j < MAXN; j += i) {
                long long sum = 1, p = i;
                while (j % p == 0) {
                    sum += p;
                    p *= i;
                }
                sum_of_divisors[j] *= sum;
            }
        }
        sum_of_divisors[i] -= i;
        is_tiny[i] = (sum_of_divisors[i] > i);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("TIHON.inp", "r")) {
        freopen("TIHON.inp", "r", stdin);
        freopen("TIHON.out", "w", stdout);
    }
    sieve();

    int n;
    cin >> n;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (is_tiny[x]) count++;
    }

    cout << count << endl;

    return 0;
}

/* 950000
Với mỗi số tự nhiên, An gọi các “ước thực sự” của nó là những ước số tự nhiên nhỏ hơn số đó.
Chẳng hạn 3 là một “ước thực sự” của 6. Thật đáng thương, số 1 chẳng có ước thực sự nào cả .
An cũng gọi một số là “số tí hon” nếu nó nhỏ hơn tổng tất cả các ước thực sự của nó. Chẳng hạn ta có 40 là một số tí hon, vì 40 nhỏ hơn tổng các ước thực sự của nó: 1+2+4+5+8+10+20=50.
An có một dãy các số tự nhiên và muốn kiểm tra xem chúng có phải là những số tí hon hay không. Hãy giúp An kiểm tra xem có bao nhiêu số tí hon trong dãy của bạn ấy nhé!
Dữ liệu vào:
    Dòng đầu tiên ghi số tự nhiên n là số lượng các số có trong dãy của An.
    Dòng tiếp theo ghi n số tự nhiên a[i] là các số trong dãy, ngăn cách nhau bởi dấu cách.
Giới hạn dữ liệu: 1 <= n <= 10^6
  1<=ai<=10^8 với mọi a[i] (các số trong dãy không vượt quá 10^8)
Kết quả: gồm một dòng duy nhất chứa một số nguyên là số lượng các số tí hon trong dãy của An.

Ví dụ:
INPUT:
3
40 12 16
--> OUTPUT: 2
*/