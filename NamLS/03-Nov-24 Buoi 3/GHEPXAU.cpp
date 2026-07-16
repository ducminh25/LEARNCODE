#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra xem một chuỗi có phải là đối xứng không
bool isPalindrome(const string &s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// Hàm tính độ dài chuỗi đối xứng liên tiếp lớn nhất
vector<int> maxPalindromeLengths(const string &s) {
    int n = s.size();
    vector<int> maxLen(n, 0);

    for (int i = 0; i < n; ++i) {
        for (int len = 0; i + len < n; ++len) {
            if (isPalindrome(s, i, i + len)) {
                maxLen[i] = max(maxLen[i], len + 1);
            }
        }
    }
    return maxLen;
}

int main() {
    string X, Y;
    cin >> X >> Y;

    vector<int> maxLenX = maxPalindromeLengths(X);
    vector<int> maxLenY = maxPalindromeLengths(Y);

    int maxPalindrome = 0;

    // Duyệt qua tất cả các vị trí có thể bắt đầu chuỗi X1 và Y1
    for (int i = 0; i < X.size(); ++i) {
        for (int j = 0; j < Y.size(); ++j) {
            maxPalindrome = max(maxPalindrome, maxLenX[i] + maxLenY[j]);
        }
    }

    cout << maxPalindrome << endl;

    return 0;
}
