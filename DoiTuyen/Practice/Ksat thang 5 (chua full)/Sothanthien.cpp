#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long reverse(long long n) {
    long long res = 0;
    while (n > 0) {
        res = res * 10 + n % 10;
        n = n / 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    if(fopen("SOTTHIEN.inp", "r")) {
        freopen("SOTTHIEN.INP", "r", stdin);
        freopen("SOTTHIEN.OUT", "w", stdout);
    }
    
    long long a, b;
    cin >> a >> b;
    
    vector<long long> friendly_numbers;
    
    for (long long i = a; i <= b; ++i) {
        if (gcd(i, reverse(i)) == 1) {
            friendly_numbers.push_back(i);
        }
    }
    
    if (friendly_numbers.empty()) {
        cout << -1;
    } else {
        for (long long num : friendly_numbers) {
            cout << num << " ";
        }
    }
    
    return 0;
}

/*
Số tự nhiên có rất nhiều tính chất thú vị: Ví dụ với số 29, số đảo ngược của nó là 92. Hai số này nguyên tố cùng nhau tức có ước chung lớn nhất là 1. Những số như thế được gọi là số thân thiện, tức là số 29 được gọi là số thân thiện, số 92 cũng được gọi là số thân thiện. Ví dụ: a = 110; b = 120. Có 6 số thân thiện từ 110 đến 120 gồm: 112 113 115 116 118 119 Dữ liệu: Vào file văn bản SOTTHIEN.INP chứa 2 số nguyên a, b (10 ≤ a ≤ b ≤ 20000). Dữ liệu ra: ghi vào tệp SOTTHIEN.OUT là các số thân thiện trong đoạn [a, b]. Nếu không có số thân thiện nào trong đoạn [a,b] thì in ra -1.
*/