#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
string a[maxn], res;
int n;

bool compare(string x, string y) {
    if(x != y) return x + y < y + x;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    n = 0;
    getline(cin, res);
    while(res != "") {
        n++;
        a[n] = res;
        getline(cin, res);
    }

    sort (a + 1, a + n + 1, compare);
    for(int i = n; i >= 1; --i) {
        cout << a[i];
    }

    return 0;
}