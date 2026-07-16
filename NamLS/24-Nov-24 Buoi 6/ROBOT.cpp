#include <bits/stdc++.h>
using namespace std;
long long s;
string go;
set<long long> vis;

void input() {
    cin >> s;
    cin.ignore();
    getline(cin, go);
}

void solve() {
    vis.insert(s);
    long long x = s;
    for (char c : go) {
        switch (c) {
            case 'L': 
                x--;
                break;
            case 'R':
                x++;
                break;
        }
        vis.insert(x);
    }
    cout << vis.size();
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    #define task "ROBOT"
    if(fopen(task".INP", "r")) {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    input();
    solve();

    return 0;
}


/*
Có một hành lang vô hạn cả hai hướng được chia thành các ô, mỗi ô rộng 1 mét, các ô được đánh số bởi các số nguyên giống như trên trục số. Chiều rộng 1 mét vừa đủ để một robot đứng. Hiện tại, robot đang đứng ở ô đánh số N.
Hà có một chuỗi lệnh cho robot thực hiện là một xâu kí tự gồm các kí tự: L, R, S với ý nghĩa: nếu gặp kí tự L thì robot sẽ đi sang trái một ô, nếu gặp R thì sang phải một ô, nếu gặp S thì đứng im. Robot sẽ thực hiện lần lượt cả chuỗi lệnh từ đầu tới cuối xâu.

Yêu cầu: Xác định xem robot sẽ thăm bao nhiêu ô khác nhau trong hành lang sau khi thực hiện xong chuỗi lệnh, tính cả ô đầu tiên Robot đứng.
Input
Vào từ file ROBOT.INP gồm:

• Dòng đầu chứa số nguyên N (|N| ≤ 10^18);

• Dòng thứ hai chứa một xâu kí tự là chuỗi lệnh của Hà (độ dài xâu không quá 10^5).

Output
Ghi ra file văn bản ROBOT.OUT gồm một số nguyên là kết quả tìm được.

Ví dụ:
INPUT:
5
RRSRRLRR
--> OUTPUT: 6
*/