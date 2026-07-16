#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string s1, s2;

void input() {
    cin >> s1 >> s2;
}

void solve() {
    string res = "-1";
    int n = s1.length(), m = s2.length();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s1[i] == s2[j]) {
                string common = "";
                int k = 0;
                while (i + k < n && j + k < m && s1[i + k] == s2[j + k]) {
                    common += s1[i + k];
                    k++;
                }
                if (res == "-1" || common > res)
                    res = common;
            }
        }
    }
    
    cout << res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if (fopen("CAU3.inp", "r")) {
        freopen("CAU3.inp", "r", stdin);
        freopen("CAU3.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}




/*
Nam là một học sinh rất đặc biệt, định nghĩa của Nam về xâu đẹp như sau: Với 2 xâu bất kì, xâu đẹp là xâu có thứ tự từ điển lớn nhất. 
Ví dụ: 2 xâu “abc” và “da” thì xâu “da” là xâu đẹp vì xâu “da” có thứ tự từ điển lớn hơn xâu “abc”. 
Một hôm, Nam nhờ các bạn trong đội tuyển học sinh giỏi của trường giải bài sau: 
Cho 2 xâu S1 và S2, gồm các chữ cái in thường, và 2 xâu này có rất nhiều xâu con chung liên tiếp hoặc đôi khi sẽ không có xâu con chung nào. 
Nếu có, trong các xâu con chung liên tiếp đó, hãy in ra xâu đẹp (hay nói cách khác là xâu có thứ tự từ điển lớn nhất). 

Dữ liệu vào:
•	Dòng đầu tiên gồm xâu S1;
•	Dòng thứ hai gồm xâu S2;
(s1.size(), s2.size() <= 10^5)
Kết quả: là một dòng duy nhất là xâu đẹp. Nếu S1 và S2 không tồn tại xâu con chung liên tiếp nào, in ra -1

Ví dụ:
INPUT:
abcsdb
sdsa
--> OUTPUT: sd
Giải thích: các xâu con chung liên tiếp là a, d, s, sd. Xâu lớn nhất là: sd
*/

/*
Để giải quyết bài toán này, chúng ta có thể sử dụng kỹ thuật hai con trỏ kết hợp với việc so sánh các xâu con chung liên tiếp. Dưới đây là một cách tiếp cận hiệu quả:

Duyệt qua tất cả các vị trí bắt đầu có thể trong s1.
Với mỗi vị trí bắt đầu, tìm xâu con chung liên tiếp dài nhất với s2.
So sánh xâu con chung tìm được với xâu đẹp nhất hiện tại, cập nhật nếu cần.
*/