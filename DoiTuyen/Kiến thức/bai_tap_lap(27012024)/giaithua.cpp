#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, n;
    long long giaithua;
    i = 1;
    giaithua = 1;
    cin>>n;
    while (i<=n) {
        giaithua = giaithua*i;
        i++;
    }
    cout<<giaithua;
    return 0;
}
