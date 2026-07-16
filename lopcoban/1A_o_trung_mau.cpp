#include <bits/stdc++.h>
using namespace std;

bool cungMau(int a, int b, int c, int d) {
    return ((a + b) % 2 == (c + d) % 2);
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (cungMau(a, b, c, d)) {
        cout << "Trung mau";
    } else {
        cout << "Khong trung mau";
    }

    return 0;
}