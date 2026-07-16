#include <bits/stdc++.h>
using namespace std;
/**
double tinhTong(int n) {
    double S = 0.0;
    for (int i = 0; i <= n; i++) {
        S += (double)(2*i + 1) / (2*i + 2);
    }
    return S;
}

int main() {
    int n;
    cin >> n;

    double S = tinhTong(n);
    cout << fixed << setprecision(2) << S;

    return 0;
}
/**/
int main ()
{
    int n;
    double s;
    cin>>n;
    for (int i=1; i<=2*n+1;i=i+2)
    {
        s = s+double(i)/(i+1);
    }
    cout<<fixed<<setprecision(2)<<s;
    return 0;
}
