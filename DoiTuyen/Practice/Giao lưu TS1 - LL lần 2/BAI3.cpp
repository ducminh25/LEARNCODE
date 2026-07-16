// #include <bits/stdc++.h>
// using namespace std;
// const int maxn = 1e5 + 5;
// int n, k, a[maxn];
// bool ok[maxn];

// void input() {
//     cin >> n >> k;
//     for (int i = 1; i <= n; ++i) {
//         cin >> a[i];
//     }
// }

// void solve() {
//     vector<int> vals[k];
//     long long res = 0;
//     for (int i = 1; i <= n; ++i) {
//         if(ok[i]) continue;
//         vals[(i - 1) % k].push_back(a[i]); // Mỗi phần tử thứ i của vector chứa một bộ gồm các số cách nhau k chỉ số
//         ok[i] = true;
//     }

//     for (int i = 1; i <= k; ++i) {
//         sort(vals[i].begin(), vals[i].end()); // Sort để tìm trung vị
//         int median = vals[i][vals[i].size() / 2];
//         for (int j = 0; j < vals[i].size(); ++j) {
//             res += abs(vals[i][j] - median); // Tính ra các chênh lệch của các số đối với trung vị là xong:D
//         }
//     }

//     cout << res << endl;
// }

// int main() {
//     ios_base :: sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     input();
//     solve();

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100001;
int n, k;
int a[MAX_N];
bool havi[MAX_N];
long long t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= k; i++) {
        if (havi[i]) continue;

        vector<int> v;
        int c = i;
        while (!havi[c]) {
            v.push_back(a[c]);
           havi[c] = true;
            c = (c + k - 1) % n + 1;
        }
        sort(v.begin(), v.end());
        int m = v[v.size() / 2];
        for (int i = 0; i < (int)v.size(); ++i) {
            t += abs(v[i] - m);
        }
    }

    cout << t;

    return 0;
}