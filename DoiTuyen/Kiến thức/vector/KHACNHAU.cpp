#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("KHACNHAU.INP", "r", stdin);
    freopen("KHACNHAU.OUT", "w", stdout);

    vector<int> numbers;
    int num;

    while (cin >> num) {
        numbers.push_back(num);
    }

    sort(numbers.begin(), numbers.end());

    int uniqueCount = numbers.empty() ? 0 : 1;
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] != numbers[i - 1]) {
            ++uniqueCount;
        }
    }

    cout << uniqueCount;
    return 0;
}