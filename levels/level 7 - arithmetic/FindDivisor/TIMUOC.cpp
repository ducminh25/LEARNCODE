#include <bits/stdc++.h>
using namespace std;
uint64_t n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie (0);
    
    cin >> n;
    // Count divisors to up to 10^15
    int cnt = 0;
    for (long long i = 1; i <= (long long)(sqrt(n)); i++)
        if (n % i == 0) {
            if(n / i == i) cnt++;
            else cnt += 2;
        }

    cout << cnt << endl;
    return 0;
}
