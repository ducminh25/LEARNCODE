#include <bits/stdc++.h>
using namespace std;

// Tìm kí tự ở vị trí thứ n
string findC (int n) {
    string s = "";
    int i = 1;
    while (s.length() < n) {
        int sq = i * i;
        s += to_string(sq);
        ++i;
    }
    
    return s.substr(n - 1, 1);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("BAI3.INP", "r")) {
        freopen("BAI3.INP", "r", stdin);
        freopen("BAI3.OUT", "w", stdout);
    }
    
    int n;
    cin >> n;
    cout << findC(n) << endl;
    return 0;
}