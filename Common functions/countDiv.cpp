// Đếm số lượng ước nguyên dương của t số nguyên
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4000005;
int divisors[maxn];

// Sàng ước
void initDiv () {
    for (int i = 1; i < maxn; i++)
        for (int j = i; j < maxn; j += i) 
            divisors[j]++;
}

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    
    initDiv ();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << divisors[n] << endl;
    }

    return 0;
}
