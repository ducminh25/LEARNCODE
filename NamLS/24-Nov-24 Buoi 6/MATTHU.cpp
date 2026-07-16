#include <bits/stdc++.h>
using namespace std;
string s;
long long n, cnta = 0, cntb = 0;

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("MATTHU.INP", "r")) {
        freopen("MATTHU.INP", "r", stdin);
        freopen("MATTHU.OUT", "w", stdout);
    }

    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'A' ||
            s[i] == '*' && s[i + 1] == 'A' ||
            s[i] == 'A' && s[i + 1] == '*' ||
            s[i] == '*' && s[i + 1] == '*')
            cnta++;
        if (s[i] == 'B' && s[i + 1] == 'B' ||
            s[i] == '*' && s[i + 1] == 'B' ||
            s[i] == 'B' && s[i + 1] == '*' ||
            s[i] == '*' && s[i + 1] == '*')
            cntb++;
    }
    cout << max(cnta, cntb);

    return 0;
}

/*
Trong hội trại năm nay, Hà được lớp giao nhiệm vụ tham gia trò chơi giải mật thư tìm kho báu. Mật thư có n kí tự chỉ gồm hai loại kí tự là 'A' và 'B'.
Trong mật thư nếu số lần chuỗi con "AA" xuất hiện nhiều hơn số lần xuất hiện của chuỗi con "BB" thì đáp án của mật thư là số lần xuất hiện chuỗi con "AA" và ngược lại.
Hà vô tình làm ướt mật thư nên một số kí tự có thể bị nhòe mực, lúc này kí tự nào bị nhòe thì kí tự đó sẽ chuyển thành kí tự '*'.
Yêu cầu: Hãy giúp Hà tìm ra một số lớn nhất có thể là đáp án của mật thư nếu nó không bị ướt.

Input
Từ tệp văn bản MATTHU.INP gồm:

+ Dòng đầu tiên chứa số nguyên dương n là độ dài của mật thư (1 <= n <= 10^6).

+ Dòng thứ hai chứa n kí tự 'A', 'B' hoặc '*' được ghi liên tiếp không chứa dấu cách.

Output
Ghi vào tệp văn bản MATTHU.OUT chỉ gồm một số nguyên duy nhất là đáp án của bài toán.
*/