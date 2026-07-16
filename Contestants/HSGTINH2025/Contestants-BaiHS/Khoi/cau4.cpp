#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
unordered_map <string, int> dem;
string s, st;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("cau4.inp", "r")){
        freopen("cau4.inp", "r", stdin);
        freopen("cau4.out", "w", stdout);
    }

    cin >> n >> k;
    cin >> s;

    int ma = 0;
    for (int i = 0; i < s.size(); i++){
        for (int j = i; j < s.size(); j++){
            string x = "";
            for (int z = i; z <= j; z++) x += s[z];
//            cout << x << '\n';
            dem[x]++;
            if (ma < x.size() && dem[x] >= k){
                ma = max(ma, dem[x]);
            }
        }
    }

    if (ma == 0){
        cout << -1;
    }
    else cout << ma;
    return 0;
}
