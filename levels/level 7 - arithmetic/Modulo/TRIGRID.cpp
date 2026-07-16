#include <bits/stdc++.h>
using namespace std;
int MOD = 2016;
long long a;

int main () {
    ios_base::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    
    cin >> a;

    // Công thức tính tổng số tam giác trong lưới tam giác MOD 2016
    // Formula to calculate the total number of triangles in the triangle grid MOD 2016.
    int d = MOD * 8;
    long long s1 = ((a % d) * ((a + 2) % d) * ((2 * a + 1) % d)) % d;
    long long s = (s1 / 8) % 2016;

    cout << s << endl;
    return 0;
}