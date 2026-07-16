#include <bits/stdc++.h>
using namespace std;

// Hàm kiểm tra xâu đối xứng
bool isPalindrome(const string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

// Hàm tìm độ dài của xâu P
int findSmallestPartitionForPalindrome(string s) {
    int n = s.length();
    
    // Duyệt từ đầu xâu đến cuối xâu
    for (int len = 1; len < n; ++len) {
        string p = s.substr(0, len); // Xâu P là phần đầu
        string q = s.substr(len);     // Xâu Q là phần còn lại
        
        // Ghép Q vào trước P
        string combined = q + p;
        
        // Nếu kết quả là xâu đối xứng, trả về độ dài của P
        if (isPalindrome(combined)) {
            return len;
        }
    }
    // Trả về 0 nếu không tìm được cách cắt phù hợp
    return 0;
}

int main() {
    string s;
    getline (cin, s);
    cout << findSmallestPartitionForPalindrome(s);
    return 0;
}