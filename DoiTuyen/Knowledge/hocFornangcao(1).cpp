#include <bits/stdc++.h>
using namespace std;
int main ()
{
//    float S;
//    int a;
//    cin>>a;
//    int i;
//    S = 1.0/a;
//    while (2<i<=100) {
//        S = S + 1/(a+i);
//        i++;
//    }
//    cout<<S;
//    return 0;
    long long a,i,n;
    cin>>a;
    float S;
    S = 1.0/a;
    n = 1;
    while (1.0/(a+n)>=0.0001) {
        S = S + 1.0/(a+n);
        n++;
    }
    cout<<S;
    return 0;
}
