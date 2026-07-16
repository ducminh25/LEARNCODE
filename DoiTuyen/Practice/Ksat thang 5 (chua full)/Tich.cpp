#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // Tìm ba số lớn nhất và hai số nhỏ nhất
    long long max1 = LLONG_MIN, max2 = LLONG_MIN, max3 = LLONG_MIN;
    long long min1 = LLONG_MAX, min2 = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        if (a[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2) {
            max3 = max2;
            max2 = a[i];
        } else if (a[i] > max3) {
            max3 = a[i];
        }

        if (a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        } else if (a[i] < min2) {
            min2 = a[i];
        }
    }

    long long result = max1 * max2 * max3;
    vector<long long> resultVec = {max1, max2, max3}; // Lưu ba số lớn nhất

    if (max1 * min1 * min2 > result) {
        result = max1 * min1 * min2;
        resultVec = {max1, min1, min2}; // Lưu số lớn nhất và hai số nhỏ nhất
    }

    sort(resultVec.begin(), resultVec.end()); // Sắp xếp kết quả

    for (long long num : resultVec) {
        cout << num << " ";
    }
    cout << "\n";
    return 0;
}   

/*
Cho một dãy gồm N số nguyên. Viết chương trình hiển thị ra màn hình 3 số trong dãy có tích T của chúng là lớn nhất.
*/