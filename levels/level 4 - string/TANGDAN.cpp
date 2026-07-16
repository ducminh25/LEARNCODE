#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    while (n--) {
        string num;
        cin >> num;
        int i = 0;
        for (; i < num.size() - 1; i++) {
            if (num[i] > num[i + 1]) {
                break;
            }
        }
        if (i == num.size() - 1) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}