#include <bits/stdc++.h>
using namespace std;
int n;
long long s[100005];
struct vehicles {
    int fine, day;
};
vehicles car[100005];

bool compare(vehicles x, vehicles y) {
    if(x.day * y.fine < y.day * x.fine) return true;
    if(x.day * y.fine > y.day * x.fine) return false;
    return false;
}

void input() {
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> car[i].fine;
    for(int i = 1; i <= n; ++i) cin >> car[i].day;
}

void solve() {
    sort(car + 1, car + n + 1, compare);
    s[0] = 0;
    for(int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + car[i].day;
    long long res = 0;
    for(int i = 1; i <= n; ++i)
        res += car[i].fine * s[i];
    
    cout << res;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    solve();
    return 0;
}
