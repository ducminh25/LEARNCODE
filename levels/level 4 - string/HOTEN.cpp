#include <bits/stdc++.h>
using namespace std;
string name[105];

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    getline(cin, name[0]);
    int count_space = 1;
    for (int i = 0; i < name[0].size(); i++) {
        if (name[0][i] == ' ') count_space++;
        else name[count_space] += name[0][i];
    }
    cout << count_space << endl;

    int maxx = 0;
    for (int i = 1; i <= count_space; ++i) {
        if(name[i].size() > maxx) maxx = name[i].size();
    }
    cout << maxx << endl;

    for (int i = 1; i <= count_space; ++i) {
        cout << name[i] << endl;
    }

    return 0;
}