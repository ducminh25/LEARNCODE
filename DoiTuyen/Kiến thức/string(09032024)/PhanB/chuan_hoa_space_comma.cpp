#include <bits/stdc++.h>
using namespace std;

string normalizeString(string s) {
    string result;
    bool capitalize = false; // đánh dấu cần viết hoa

    for (int i = 0; i < s.length(); ++i) {
        // Bỏ dấu cách thừa sau chấm, phẩy
        if (s[i] == ' ' && (i + 1 < s.length() && (s[i + 1] == ',' || s[i + 1] == '.'))) {
            continue;
        }

        if (s[i] == ',' || s[i] == '.') {
            // Thêm space bị thiếu (nếu không có)
            result += s[i];
            if (i + 1 == s.length() || s[i + 1] != ' ') {
                result += ' ';
            }
            
            capitalize = true;
        } else if (s[i] == ' ') {
            result += s[i];
            // Giữ nguyên đánh dấu khi sau dấu chấm là dấu cách (thứ mà cần phải loại bỏ)
        } else {
            if (capitalize && s[i] != ' ') {
                result += toupper(s[i]);
                capitalize = false; // Đặt lại
            } else {
                result += s[i];
            }
        }
    }
    return result;
}

int main() {
    string text;
    getline(cin, text);

    string normalizedText = normalizeString(text);
    cout << normalizedText << endl;

    return 0;
}