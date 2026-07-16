#include <bits/stdc++.h>
using namespace std;

const int maxn = 10005;
int t;
vector<int> ans;
int freq[maxn];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("TenGoi.Inp", "r")) {
        freopen("TenGoi.Inp", "r", stdin);
        freopen("TenGoi.Out", "w", stdout);
    }

    cin >> t;
    int tmp = t;
    while (t--) {
        string name;
        cin >> name;
        int size = name.size();
        // bool check[size];

        for (int i = 0; i < size; ++i)
            if (name[i] == 'W' || name[i] == 'A' || name[i] == 'R')
                name[i] = ' ';
        
        int count = 0, res = 0;
        for (int i = 0; i < size; ++i) {
            if (name[i] != ' ') {
                count++;
                res = max(res, count);
            }
            else count = 0;
        }
        ans.push_back(res);
    }

    for (int i = 0; i < tmp; ++i)
        freq[ans[i]]++;

    int max_len = 0;
    for (int i = 0; i < maxn; ++i) {
        if (freq[i] > 0)
            max_len = i;
    }
    if (max_len == 0)
        cout << "NO" << endl;
    else
        cout << max_len << " " << freq[max_len] << endl;
    
    return 0;
}