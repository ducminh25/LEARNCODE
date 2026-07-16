#include <bits/stdc++.h>
using namespace std;
int n;
struct student {
    string name;
    int math, it, num;
};
student a[1000005];

void input() {
    cin >> n;
    cin.ignore();
    for(int i = 1; i <= n; ++i) {
        getline(cin, a[i].name);
        cin >> a[i].math >> a[i].it;
        a[i].num = i;
        cin.ignore();
    }
}

bool compare(student &x, student &y) {
    if(x.math + x.it > y.math + y.it) return true;
    if(x.math + x.it < y.math + y.it) return false;
    if(x.it > y.it) return true;
    if(x.it < y.it) return false;
    if(x.num < y.num) return true;
    if (x.num > y.num) return false;
    return true;
}

void solve() {
    sort(a + 1, a + n + 1, compare);
    cout << a[1].num << endl; cout << a[1].name << endl;
    cout << a[2].num << endl; cout << a[2].name << endl;
    cout << a[3].num << endl; cout << a[3].name << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();

    return 0;
}
