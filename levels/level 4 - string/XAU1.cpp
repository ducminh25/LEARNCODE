#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    getline(cin, a);
    int n = a.size();
    getline(cin, b);
    int m = b.size();

    if (n > m)
        cout << "A dai hon B " << n - m << " ki tu" << endl;
    else if (n < m)
        cout << "B dai hon A " << m - n << " ki tu" << endl;
    else
        cout << "hai xau dai bang nhau" << endl;
    return 0;
}