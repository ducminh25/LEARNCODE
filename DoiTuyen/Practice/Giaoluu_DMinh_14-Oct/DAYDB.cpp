#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("DAYDB.INP", "r")) {
        freopen("DAYDB.INP", "r", stdin);
        freopen("DAYDB.OUT", "w", stdout);
    }
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    // Lưu chỉ số của mỗi phần tử trong dãy
    unordered_map<int, vector<int>> index;
    for (int i = 0; i < n; ++i) {
        index[arr[i]].push_back(i);
    }

    // Tính tổng dồn
    long long prefixSum[n + 1] = {0};
    for (int i = 0; i < n; ++i)
        prefixSum[i + 1] = prefixSum[i] + arr[i];

    // Tìm tổng lớn nhất
    long long max_sum = LLONG_MIN;
    for (auto& pair : index) {
        vector<int>& idx = pair.second;
        if (idx.size() < 2) continue; // Nếu xuất hiện chỉ một lần

        for (int i = 0; i < idx.size() - 1; ++i) {
            for (int j = i + 1; j < idx.size(); ++j) {
                long long sum = prefixSum[idx[j] + 1] - prefixSum[idx[i]];
                max_sum = max(max_sum, sum);
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}