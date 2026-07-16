#include <bits/stdc++.h>
using namespace std;

int n, t;
// int a [100005], b[1005];

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    if (fopen ("HONUOC.INP", "r")) {
        freopen ("HONUOC.INP", "r", stdin);
        freopen ("HONUOC.OUT", "w", stdout);
    }
    
    cin >> n >> t;
    vector <pair <int, int>> vec;
    long long sum_init = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
        sum_init += a;
    }

    cout << sum_init << endl;
    long long sum = 0;
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < n; ++j) {
            vec[j].first -= vec[j].second;
            if (vec[j].first < 0) vec[j].first = 0;
            sum += vec[j].first;
        }
        cout << sum << endl;
        sum = 0;
    }

    return 0;
}