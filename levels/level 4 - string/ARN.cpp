#include <bits/stdc++.h>
using namespace std;
string s, x;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s >> x;
    int cnt = 0;
    while (s.find(x) != string::npos) {
        // Thay thế xâu tìm thấy bằng xâu rỗng
        s.replace(0, s.find(x) + x.length(), ""); // replace the found string to an empty string
        cnt++;
    }
    cout << cnt;

    return 0;
}