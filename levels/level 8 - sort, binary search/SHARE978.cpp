#include <bits/stdc++.h>
using namespace std;
int n;
long long m;
vector<pair<int, int>> hs;

void input() {
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        hs.push_back({x, i});
    }
}

void solve() {
    sort(hs.begin(), hs.end());
    long long total = 0;
    for(int i = 0; i < n; ++i) total += hs[i].first;
    if(total < m) {
        cout << -1 << endl;
        return;
    }
    
    vector<long long> result(n + 1, 0);
    long long remain = m; // Số tiền còn lại cần trả.
    int rstudent = n; // Số học sinh chưa trả tiền.
    
    for(int i = 0; i < n; ++i) {
        long long avg = remain / rstudent;
        // Nếu học sinh không có đủ tiền bằng avg, thì phải trả hết tiền
        if(hs[i].first <= avg) {
            result[hs[i].second] = hs[i].first; // Lưu vào mảng res là số tiền mà học sinh i cần trả
            remain -= hs[i].first; // Trừ đi số tiền đã được trả vào biến lưu số tiền cần trả còn lại
        }
        // Nếu không thì trả tiền bằng avg
        else {
            result[hs[i].second] = avg;
            remain -= avg;
        }
        rstudent--;
    }

    for(int i = 1; i <= n; ++i) {
        cout << result[i] << " ";
    }
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
