#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    getline (cin, a);
    getline (cin, b);

    // Mảng để đếm số lượng xuất hiện của mỗi ký tự trong xâu a và b
    int countA[256] = {}, countB[256] = {};

    // Đếm số lượng xuất hiện của mỗi ký tự trong xâu a
    for (char ch : a) {
        countA[ch]++;
    }

    // Đếm số lượng xuất hiện của mỗi ký tự trong xâu b
    for (char ch : b) {
        countB[ch]++;
    }

    // Tính khoảng cách: số lượng ký tự cần xóa
    int distance = 0;
    for (int i = 0; i < 256; i++) {
        distance += abs(countA[i] - countB[i]);
    }

    cout << distance << endl;

    return 0;
}