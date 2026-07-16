#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int maxn = 3005;
int n;
vector<int> a;

void input() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
}

void solve() {
    sort(a.begin(), a.end());
    int acute = 0, right = 0, obtuse = 0;
    
    for (int i = 0; i < n - 2; ++i) {
        int k = i + 2;
        for (int j = i + 1; j < n - 1; ++j) {
            while (k < n && a[i] + a[j] > a[k]) k++;
            
            int count = k - j - 1;
            if (count <= 0) continue;
            
            obtuse += count;
            
            if (a[i] * a[i] + a[j] * a[j] < a[k-1] * a[k-1])
                acute += count;
            else if (a[i] * a[i] + a[j] * a[j] == a[k-1] * a[k-1]) {
                acute += count - 1;
                right++;
            }
            else {
                int l = j + 1, r = k - 1;
                while (l <= r) {
                    int mid = l + (r - l) / 2;
                    if (a[i] * a[i] + a[j] * a[j] == a[mid] * a[mid]) {
                        right++;
                        acute += mid - j - 1;
                        obtuse -= 1;
                        break;
                    }
                    else if (a[i] * a[i] + a[j] * a[j] < a[mid] * a[mid]) {
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                if (l > r) acute += count;
            }
        }
    }
    
    cout << acute << " " << right << " " << obtuse << endl;
}

signed main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("BAI5.inp", "r")) {
        freopen("BAI5.inp", "r", stdin);
        freopen("BAI5.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}
