#include <bits/stdc++.h>
using namespace std;

bool canFormLogin(const string &s) {
    string target = "login";
    int j = 0;
    for (char c : s) {
        if (c == target[j])
            j++;
        if (j == target.size())
            return true;
    }
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("DANGNHAP.inp", "r")) {
        freopen("DANGNHAP.inp", "r", stdin);
        freopen("DANGNHAP.out", "w", stdout);
    }
    
    int n;
    cin >> n;
    vector<int> valid;
    
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if (canFormLogin(s)) 
            valid.push_back(i);
    }
    
    cout << valid.size() << endl;
    for (int idx : valid) {
        cout << idx << ' ';
    }
    
    return 0;
}