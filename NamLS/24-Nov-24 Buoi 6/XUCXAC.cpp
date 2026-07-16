#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
vector<int> x;
bool ok = true;

int toInt (char a) {
    return a - '0';
}

void input() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); ++i) {
        if(!isdigit(toInt(s[i]))) {
            ok = false;
        }
        int c = toInt(s[i]);
        x.push_back(c);
    }
}

void solve() {
    int res = 0;
    bool cur_player = false;
    
    for(int i = 0; i < x.size(); ++i) {
        if(x[i] < 1 || x[i] > 6) {
            cout << -1;
            return;
        }
        
        if(!cur_player) {
            res++;
            cur_player = true;
        }
        
        if(x[i] != 6) {
            cur_player = false;
        }
    }
    
    if(x[x.size() - 1] != 6)
        cout << res;
    else cout << -1;
}
int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("XUCXAC.inp", "r")) {
        freopen("XUCXAC.inp", "r", stdin);
        freopen("XUCXAC.out", "w", stdout);
    }

    input();
    solve();

    return 0;
}

/*
Giờ ra chơi, các bạn học sinh lớp học thầy Nam chơi trò chơi rất nhàm chán như sau: 
mỗi người lần lượt tung xúc xắc, nếu ai tung vào số 6 thì sẽ được chơi tiếp (tung lại), 
còn không thì sẽ đến lượt người khác. 
Trung ghi lại tất cả các số xúc xắc mà mọi người tung được rồi đố người bạn thân Hỏa Anh Tú xem đã có tất cả bao nhiêu người chơi. 
Biết rằng xúc xắc có 6 mặt, đánh số từ 1 đến 6 và mỗi người chỉ tham gia chơi nhiều nhất một lần.
Input: Vào từ file XUCXAC.INP gồm một dòng là dãy số xúc xắc tung được, viết liền nhau như một xâu kí tự (độ dài không quá 10^5);
Output Ghi ra file văn bản XUCXAC.OUT gồm một số là số người đã chơi hoặc in ra -1 nếu dãy số không hợp lệ.
*/