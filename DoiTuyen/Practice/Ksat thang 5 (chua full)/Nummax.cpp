#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    // freopen ("Nummax.INP", "r", stdin);
    // freopen ("Nummax.OUT", "w", stdout);
    // BAI5
    int n, k;
    cin >> n >> k;
    cin.ignore ();
    string num;
    getline (cin, num);

    stack<char> st;

    for (char c : num) {
        while (!st.empty() && st.top() < c && k > 0) {
            st.pop();
            --k;
        }
        st.push(c);
    }

    while (k--) {
        if (!st.empty()) st.pop();
    }

    string result;
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    reverse(result.begin(), result.end());

    cout << result << endl;
    return 0;
}

/*
Trong giờ học môn toán, Cuội ngồi nghe cô giáo giảng bài rất chăm chú, còn Bờm, có vẻ như đang buồn ngủ vì sở thích của anh chàng là các môn Khoa học Xã hội. 
Để giúp Bờm tỉnh táo, Cuội tổ chức một trò chơi cho Bờm bằng cách viết ra giấy một số nguyên dương gồm N chữ số, yêu cầu Bờm tìm số lớn nhất có thể sau ghi gạch bỏ đi K chữ số trong số N chữ số đã cho.
Dữ liệu vào: NUMMAX.INP
Dòng đầu: ghi hai số nguyên N và K, cách nhau bởi một dấu cách (1 <= K <= N <= 50000)
- Dòng thứ hai: ghi xâu N chữ số, chữ số đầu tiên luôn khác 0.
Dữ liệu ra: ghi ra file văn bản NUMMAX.OUT kết quả tìm được trên một dòng duy nhất.

Ví dụ:
INPUT:
3 1
991
--> OUTPUT: 99

4 2
1924
--> 94
*/