#include <bits/stdc++.h>
using namespace std;
vector<int> res;
bool used[10] = {false};

bool backtrack(int aim, int sum, int start) {
    if (sum == aim) {
        return true;
    }
    
    for (int i = start; i >= 1; i--) {
        if (!used[i] && sum + i <= aim) {
            used[i] = true;
            res.push_back(i);
            
            if (backtrack(aim, sum + i, i - 1)) {
                return true;
            }
            
            used[i] = false;
            res.pop_back();
        }
    }
    
    return false;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("SONN.inp", "r")) {
        freopen("SONN.inp", "r", stdin);
        freopen("SONN.out", "w", stdout);
    }

    int n;
    cin >> n;
    backtrack(n, 0, 9);
    
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i];
    }
    cout << endl;
    
    return 0;
}