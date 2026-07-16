#include <bits/stdc++.h>
using namespace std;

int minstacks(int n, vector<int>& a, vector<int>& b) {
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; ++i) {
        books[i] = {a[i], b[i]};
    }

    sort(books.begin(), books.end());
    multiset<int> stacks;
    
    for (auto& book : books) {
        int bi = book.second;
        
        auto it = stacks.upper_bound(bi);
        if (it != stacks.end()) {
            stacks.erase(it);
        }
        stacks.insert(bi);
    }
    
    return stacks.size();
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU5.inp", "r")) {
        freopen("CAU5.inp", "r", stdin);
        freopen("CAU5.out", "w", stdout);
    }

    int t;
    cin >> t;
    vector<int> res;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        
        res.push_back(minstacks(n, a, b));
    }
    
    for (int r : res) {
        cout << r << endl;
    }

    return 0;
}