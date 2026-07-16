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

    unordered_map<int, vector<int>> indices;
    for (int i = 0; i < n; ++i) {
        indices[arr[i]].push_back(i);
    }

    long long prefixSum[n + 1] = {0};
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + arr[i];
    }

    long long max_sum = LLONG_MIN;
    for (auto& pair : indices) {
        vector<int>& idxs = pair.second;
        if (idxs.size() < 2) continue;

        for (int i = 0; i < idxs.size() - 1; ++i) {
            for (int j = i + 1; j < idxs.size(); ++j) {
                long long sum = prefixSum[idxs[j] + 1] - prefixSum[idxs[i]];
                max_sum = max(max_sum, sum);
            }
        }
    }

    cout << max_sum << endl;

    return 0;
}