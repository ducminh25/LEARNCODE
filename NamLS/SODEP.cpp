/*
Một số nguyên dương được gọi là SỐ ĐẸP nếu nó chỉ gồm chữ số 0 và chữ số K (hoặc một trong hai chữ số đó).
Yêu cầu: Cho số nguyên dương N (n <= 10^5) và chữ số K, hãy tìm SỐ ĐẸP nhỏ nhất là bội của N. (input luôn đảm bảo có kết quả)
13 7 --> 7007

BFS:

*/
#include <bits/stdc++.h>
using namespace std;

// findSmallestMultiple
string solve(int n, int k) {
    queue<string> q;
    set<int> vis;
    
    q.push(to_string(k));
    
    while (!q.empty()) {
        string current = q.front();
        q.pop();
        
        int remainder = 0;
        for (char c : current) {
            remainder = (remainder * 10 + (c - '0')) % n;
        }
        
        if (remainder == 0) {
            return current;
        }
        
        if (vis.find(remainder) == vis.end()) {
            vis.insert(remainder);
            q.push(current + "0");
            q.push(current + to_string(k));
        }
    }
    
    return ""; // Never happen
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("SODEP.inp", "r")) {
        freopen("SODEP.inp", "r", stdin);
        freopen("SODEP.out", "w", stdout);
    }
    
    int n, k;
    cin >> n >> k;
    cout << solve(n, k) << endl;
    
    return 0;
}
