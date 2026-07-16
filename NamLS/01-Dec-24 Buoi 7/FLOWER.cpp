#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int t;
string s1, s2;
int f1[90], f2[90];

void input() {
    getline(cin, s1);
    getline(cin, s2);
}

int calc(int l1, int l2, int l3, int l4) {
    return abs(l1 - l2) + abs(l2 - l3) + abs(l3 - l4) + abs(l4 - l1);
}

int findmin(const string &s1, const string &s2) {
    int minn = INT_MAX;
    int len1 = s1.size();
    int len2 = s2.length();

    for (int i = 0; i < len1; ++i) {
        for (int j = 0; j < len2; ++j) {
            if(s1[i] == s2[j]) {
                int l1 = i;
                int l2 = j;
                int l3 = len1 - i - 1;
                int l4 = len2 - j - 1;
                int t = calc(l1, l2, l3, l4);
                minn = min(minn, t);
            }
        }
    }
    return minn;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("FLOWER.inp", "r")) {
        freopen("FLOWER.inp", "r", stdin);
        freopen("FLOWER.out", "w", stdout);
    }
    cin >> t;
    cin.ignore();
    while(t--) {
        input();
        cout << findmin(s1, s2) << endl;
    }

    return 0;
}
