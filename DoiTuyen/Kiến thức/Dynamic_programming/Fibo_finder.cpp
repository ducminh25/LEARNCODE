#include <bits/stdc++.h>
using namespace std;
int memo [1000005] = {0};
int result;
int fibo (int n) {
    if (memo [n] != 0) return memo [n];
    if (n == 1 || n == 2) result = 1;
    else result = fibo (n - 1) + fibo (n - 2);
    memo [n] = result;
    return result;
}

int fibo_bottom_up (int n) {
    int f [n + 1];
    f [1] = 1;
    f [2] = 1;
    for (int i = 3; i <= n; ++i) {
        f [i] = f [i - 1] + f [i - 2];
    }
    return f [n];
}

int main () {
    int n;
    cin >> n;
    // cout << fibo (n) << endl;
    cout << fibo_bottom_up (n) << endl;
    return 0;
}