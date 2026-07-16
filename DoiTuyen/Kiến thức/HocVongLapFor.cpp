#include <bits/stdc++.h>
using namespace std;
int main ()
{
    long long a, b, S;
    S = 0;
    cout<<"Nhap a va b: ";
    cin>>a>>b;
    if (a<b) {
        for (a; a<=b; a++) {
            if (a%3==0) {
                S = S + a;
            }
        }
        cout<<S;
    }
    else cout<<"Nhap lai so a va b.";
    return 0;

    //cout<<"Nhap so nguyen n: ";
    //cin>>n;
    //S = 0;
    //for (int i = 1; i<=n; i++) {
    //    S = S + i*i;
    //}
    //cout<<S;
    //return 0;
}
