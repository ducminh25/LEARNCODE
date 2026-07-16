#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int chiaMang(vector<int>& a) {
    int total = accumulate(a.begin(), a.end(), 0);
    if (total % 2 != 0) {
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < a.size(); i++) {
        sum += a[i];
        if (sum == total / 2) {
            return i + 1;
        }
    }

    return 0;
}

int main() {  
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = chiaMang(a);
    if (result == 0) {
        cout << "0";
    } else {
        cout << result;
    }

    return 0;
}

