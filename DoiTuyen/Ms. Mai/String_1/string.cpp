#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("string.inp", "r", stdin);
    // freopen("string.out", "w", stdout);
    
    string s1, s2;
    
    while (cin >> s1 >> s2) 
    {
        if (s1 == "END" && s2 == "END") 
            break;
        
        int freq1[256] = {0}, freq2[256] = {0};
        
        for (char c : s1) 
            freq1[c]++;
        for (char c : s2) 
            freq2[c]++;
        
        bool same = true;
        for (int i = 0; i < 256; i++) {
            if (freq1[i] != freq2[i]) {
                same = false;
                break;
            }
        }
        
        if (same)
            cout << "same" << endl;
        else
            cout << "different" << endl;
    }
    
    return 0;
}

/*
Bài toán đặt ra là cho trước các cặp xâu ký tự, đều chỉ bao gồm các chữ cái viết thường, 
hay xác định xem mỗi cặp xâu có được tạo ra từ cùng một bộ ký tự giống nhau hay 
không. 
Chú ý: các ký tự lặp cũng phải được xem xét. Ví dụ: “abc”và “aabbbcccc” không được 
xem là tạo nên bởi cùng một bộ ký tự vì xâu thứ 2 các chữ cái được lặp lại nhiều lần hơn.
INPUT
 Gồm nhiều bộ test, mỗi bộ test gồm hai dòng ghi hai xâu cần kiểm tra, chỉ bao gồm các 
ký tự viết thường và không quá 1000 ký tự. Input kết thúc khi gặp hai dòng ghi chữ END.
OUTPUT
 Với mỗi bộ test, ghi ra màn hình thứ tự bộ test và kết quả bài toán (same hoặc 
different).

*/