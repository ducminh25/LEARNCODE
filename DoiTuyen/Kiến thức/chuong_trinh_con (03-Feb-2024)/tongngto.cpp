#include <bits/stdc++.h>
using namespace std;
bool nguyento (long long n) {
    if (n<2) return false;
    for (long long i = 2; i*i<=n; i++) {
        if (n%i==0) return false;
    }
    return true;
}
int main ()
{
    long long n;
    long long tong = 0;
    cin>>n;
    for (long long i = n; i>=2; i--) {
        if (nguyento (i)) tong += i;
    }
    cout<<tong;
    return 0;
}
