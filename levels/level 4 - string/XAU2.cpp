#include <bits/stdc++.h>
using namespace std;

string a, b;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    getline(cin, a);
    getline(cin, b);

    // Get the last character of string b
    char c = b[b.size() - 1];
    int count = 0;
    for (char x : a) {
        if (x == c) count++;
    }
    
    if (count > 0) cout << "co " << count << " ki tu " << c << " trong xau A" << endl;
    else cout << "khong co ki tu " << c << " trong xau A";

    return 0;
}