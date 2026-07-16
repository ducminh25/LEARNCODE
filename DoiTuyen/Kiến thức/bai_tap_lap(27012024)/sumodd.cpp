#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin>>n;
    long long S = 0;
    for (int i = 1; i <= n; i+=2)
    {
        S = S + i;
    }
    cout<<S;
    return 0;
}
