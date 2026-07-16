#include <bits/stdc++.h>
using namespace std;
struct bt {
    int a, b;
};
bt p[100001];
int n, c, t = 0;

bool compare(bt u, bt v) {
    if(u.a < v.a) return true;
    else return false;
}

void input() {
    cin >> n >> c;
    for(int i = 1; i <= n; ++i) {
        cin >> p[i].a >> p[i].b;
    }
}

void sol() {
    sort(p + 1, p + n + 1, compare);
    int cnt = 0;
    for(int i = 1; i <= n; ++i) {
        if(c >= p[i].a) {
            c += p[i].b;
            cnt++;
        }
        else break;
    }
    cout << cnt << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    sol();

    return 0;
}
