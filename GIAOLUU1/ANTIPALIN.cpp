/**
 * Author: Mon
 * Problem: Next Anti-Palindrome (Standard Version)
 * Complexity: O(N * K) - Thực tế là O(N) vì K hằng số nhỏ (K <= 26)
 */
#include <bits/stdc++.h>
using namespace std;

// Tăng tốc độ nhập xuất
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);

int n, k;
string s;

// Hàm kiểm tra xung đột cục bộ
// Trả về true nếu ký tự c hợp lệ tại vị trí pos
inline bool isValid(int pos, char c, const string& current_s) {
    if (pos - 1 >= 0 && current_s[pos - 1] == c) return false;
    if (pos - 2 >= 0 && current_s[pos - 2] == c) return false;
    return true;
}

void solve() {
    if (!(cin >> n >> k >> s)) return;

    int pivot = -1;

    // BƯỚC 1: Tìm vị trí "gãy" (Pivot) từ phải sang trái
    // Cố gắng tăng ký tự tại s[i] lên một mức nhỏ nhất có thể
    for (int i = n - 1; i >= 0; --i) {
        for (char c = s[i] + 1; c < 'a' + k; ++c) {
            if (isValid(i, c, s)) {
                s[i] = c;      // Chốt ký tự mới tại pivot
                pivot = i;     // Lưu vị trí
                goto BUILD_SUFFIX; // Thoát ngay để sang bước 2
            }
        }
    }

    // Nếu chạy hết vòng lặp mà không tìm được pivot -> Vô nghiệm
    cout << "NO\n";
    return;

BUILD_SUFFIX:
    // BƯỚC 2: Xây dựng lại phần đuôi (Suffix) từ sau pivot
    // Quy tắc: Chọn ký tự nhỏ nhất có thể ('a', 'b'...) để chuỗi có giá trị nhỏ nhất
    for (int i = pivot + 1; i < n; ++i) {
        for (char c = 'a'; c < 'a' + k; ++c) {
            if (isValid(i, c, s)) {
                s[i] = c;
                break; // Tìm thấy ký tự nhỏ nhất hợp lệ, chốt ngay và chuyển sang i tiếp theo
            }
        }
    }

    cout << s << "\n";
}

int main() {
    fast_io;
    solve();
    return 0;
}