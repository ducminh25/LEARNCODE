#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int maxNestedBoxes(vector<pair<int, int>> &boxes) {
    // Sorting the boxes
    sort(boxes.begin(), boxes.end(), compare);

    // Extracting the second dimension
    vector<int> dp;
    for (auto &box : boxes) {
        auto it = lower_bound(dp.begin(), dp.end(), box.second);
        if (it == dp.end())
            dp.push_back(box.second);
        else
            *it = box.second;
    }
    return dp.size();
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> boxes(N);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        boxes[i] = {a, b};
    }
    cout << maxNestedBoxes(boxes) << endl;
    return 0;
}