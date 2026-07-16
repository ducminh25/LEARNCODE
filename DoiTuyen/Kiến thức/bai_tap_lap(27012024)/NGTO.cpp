#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long n;
    cin>>n;
    if (n < 2) {
    cout << "NO" << endl;
    return 0;
  }

    for (long long i = 2; i  <= sqrt(n); ++i) {
        if (n % i == 0) {
        cout << "NO" << endl;
        return 0;
    }
  }

    cout << "YES" << endl;
    return 0;
}
