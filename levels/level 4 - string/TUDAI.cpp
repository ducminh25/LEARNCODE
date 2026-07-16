#include <bits/stdc++.h>
using namespace std;
string s;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    getline(cin, s);
    string sd = "", smax = "";
    int maxx = 0, d = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != ' ') {
            sd += s[i];
            d++;
        }
        else {
            sd = "";
            d = 0;
        }
        if (d >= maxx) {
            maxx = d;
            smax = sd;
        }
    }
    cout << maxx << endl << smax << endl;

    return 0;
}