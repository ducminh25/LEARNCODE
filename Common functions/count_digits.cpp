#include <iostream>
using namespace std;

// đếm số chữ số
int countDigits (int n) {
    int count = 0;
    while (n > 0) {
        n = n / 10;
        ++count;
    }
    return count;
}

int main () {
    int N;
    cin >> N;
    cout << countDigits (N);
    return 0;
}
