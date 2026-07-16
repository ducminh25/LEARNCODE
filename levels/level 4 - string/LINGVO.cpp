#include <bits/stdc++.h>
using namespace std;

string name[10];
int t;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i <= 9; ++i) {
        cin >> name[i];
        // cout << name[i] << " ";
    }
    
    cin >> t;
    while (t--) {
        int n, a;
        cin >> n;
        string maxx = "";
        if (n == 0) cout << name[0] << endl;
        else {
            while (n > 0) {
                a = n % 10;
                if(name[a] > maxx) maxx = name[a];
                n = n / 10;
            }
            cout << maxx << endl;
        }
    }

    return 0;
}