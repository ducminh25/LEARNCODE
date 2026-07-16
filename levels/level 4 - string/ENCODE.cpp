#include <bits/stdc++.h>
using namespace std;
char s[10];

void sum() {
    int sum = 0;
    for (int i = 1; i <= 10; ++i)
        sum += s[i] * i;
    cout << sum;
}

bool check11(int sum) {
    return sum % 11 == 0;
}

int stringToInt(char s) {
    return s - '0';
}

int main() {
    for (int i = 1; i <= 10; ++i)
        cin >> s[i];
    for (int i = 1; i <= 10; ++i) {
        if (s[i] == '?') {
            for (int j = 0; j <= 9; ++j) {
                s[i] = j + '0';
                int sum = 0;
                for (int k = 1; k <= 10; ++k)
                    sum += stringToInt(s[k]) * k;
                if (check11(sum)) {
                    cout << s;
                    return 0;
                }
            }
        }
    }
}