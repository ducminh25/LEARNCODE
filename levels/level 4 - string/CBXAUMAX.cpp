#include <bits/stdc++.h>
using namespace std;
int n;
string a [1005];

void xau_lon_nhat () {
    int maxx = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > a[maxx]) maxx = i;
    }

    cout << a[maxx] << endl;
}

void xau_dai_nhat() {
    int max_len = 0;
    string temp;
    for (int i = 0; i < n; ++i) {
        if (a[i].size() > max_len) {
            temp = a[i];
            max_len = a[i].size();
        }
    }

    cout << temp << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    cin.ignore();
    // Input
    for (int i = 0; i < n; ++i) {
        getline(cin, a[i]);
    }

    xau_lon_nhat();
    xau_dai_nhat();
    return 0;
}