#include <iostream>
using namespace std;
int main()
{
    int x, n, luythua = 1;
    cin >> x >> n;
    for (int i = 0; i < n; i++) {
        luythua *= x;
    }
    cout << luythua;
    return 0;
}
