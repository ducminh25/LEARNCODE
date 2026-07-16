#include <bits/stdc++.h>
using namespace std;

int countFriendNumbers(long long N) {
    long long count = 0;
    for (long long A = 1; A < N; A++) {
        for (long long B = 1; A * B < N; B++) {
            long long C = N - A * B;
            if (C > 0) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen ("BSBB.INP", "r", stdin);
    //freopen ("BSBB.OUT", "w", stdout);
    long long n;
    cin >> n;
    cout << countFriendNumbers(n) << endl;
    return 0;
}