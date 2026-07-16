#include<iostream>
using namespace std;

bool check(int n) {
    int count = 1;
    while (n > 0) {
        int digit = n % 10;
        if (count % 2 == 0 && digit % 2 != 0) return false;
        if (count % 2 != 0 && digit % 2 == 0) return false;
        n /= 10;
        count++;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    if (check(N)) cout << "YES";
    else cout << "NO";
    return 0;
}

