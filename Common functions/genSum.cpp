#include <bits/stdc++.h>
using namespace std;
vector<int> a;
set<long long> s;

// Sinh ra tất cả các tổng có thể của mảng a (Giới hạn mảng a 20 phần tử)
void genSum(int i, long long sum) {
    if (i == a.size()) {
        if (sum != 0) {
            s.insert(sum);
        }
        return;
    }
    genSum(i + 1, sum);
    genSum(i + 1, sum + a[i]);
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    
    genSum(0, 0);
    for (const auto &sum : s) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
