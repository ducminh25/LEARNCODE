#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long m,n,a,ucln;
    cin>>m>>n;
    m=abs(m);
    n = abs(n);
    while (m!=0 && n!=0)
    {
        if (m>n) m=m%n;
        else n = n%m;
    }
    ucln = (m+n);
    cout<<ucln;
    return 0;
}
