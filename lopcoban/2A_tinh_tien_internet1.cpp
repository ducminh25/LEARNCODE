#include <iostream>
using namespace std;

int tinhTienInternet(int n) {
    if (n <= 60) {
        return n * 80;
    } else if (n <= 120) {
        return 60 * 80 + (n - 60) * 50;
    } else {
        return 60 * 80 + 60 * 50 + (n - 120) * 30;
    }
}

int main() {
    int n;
    cin >> n;

    int tien = tinhTienInternet(n);
    cout << tien;

    return 0;
}
