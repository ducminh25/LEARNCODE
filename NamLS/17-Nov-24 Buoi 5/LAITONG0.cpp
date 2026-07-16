#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2505;
int n;
int a[MAXN], b[MAXN], c[MAXN], d[MAXN];
   
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("LAITONG0.inp", "r")) {
        freopen("LAITONG0.inp", "r", stdin);
        freopen("LAITONG0.out", "w", stdout);
    }
    
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    vector<int> sums;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sums.push_back(a[i] + b[j]);
        }
    }
    sort(sums.begin(), sums.end());

    long long cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int tmp = -(c[i] + d[j]);
            cnt += upper_bound(sums.begin(), sums.end(), tmp) - 
                lower_bound(sums.begin(), sums.end(), tmp);
        }
    }
    cout << cnt << endl;
    
    return 0;
}