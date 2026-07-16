#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int n, d[maxn];

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> d[i];
}

map<int, int> mp;

bool cmp1(pair<int, int> a, pair<int, int> b) {
    return a.first > b.first;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

void solve() {
    for (int i = 0; i < n; ++i) mp[d[i]]++;
    vector<pair<int, int>> res;
    for (auto p : mp)
        if (p.second >= 2) res.push_back(p);

    if (res.size() < 2) {
        cout << -1;
        return;
    }
    sort(res.begin(), res.end(), cmp1);
    long long area = 0;
    for (int i = 0; i < res.size() - 1; ++i) {
        if (res[i].second >= 4)
            area = max(area, (long long)res[i].first * res[i].first);
        if (res[i].second >= 2 && res[i + 1].second >= 2)
            area = max(area, (long long)res[i].first * res[i + 1].first);
    }
    if (area == 0)
        cout << -1;
    else
        cout << area;
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("HCN.inp", "r")) {
        freopen("HCN.inp", "r", stdin);
        freopen("HCN.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}

/*
Bạn cần chọn ra 4 đoạn thẳng để có thể xếp thành một hình chữ nhật.
Giả sử 4 đoạn thẳng mà bạn chọn có độ dài lần lượt là a,b,c,d (a <= b <= c <= d),
khi đó có thể xếp được thành một hình chữ nhật nếu a=b và c=d.
Bạn xếp được hình chữ nhật có diện tích càng lớn sẽ càng được điểm cao.

Yêu cầu: Cho d1, d2, ..., dn là độ dài của n đoạn thẳng.
Hãy tìm cách chọn 4 đoạn thẳng để xếp được thành một hình chữ nhật có diện tích lớn nhất.
*/