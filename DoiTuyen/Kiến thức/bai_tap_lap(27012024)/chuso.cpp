#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n, chuso;
    chuso = 0;
    cin>>n;
    int S;
    S = 0;
    while (n > 0) {
        chuso++;
        S += n%10;
        n /= 10;
    }
    cout<<chuso<<" "<<S;
}
