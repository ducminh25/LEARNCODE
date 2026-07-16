#include <bits/stdc++.h>
using namespace std;
long long gcd (long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main ()
{
    long long a,b;
    cin>>a>>b;
    long long c = gcd (a, b);
    if (b==0) return 0;
    else
    {
        a = a / c;
        b = b / c;
    }
    cout << a << " " << b;
    return 0;
}