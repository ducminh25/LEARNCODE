#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
vector<int> a;

int solve(vector<int>& a) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int x : a) {
        if (!pq.empty() && pq.top() < x) {
            pq.pop();
        }
        pq.push(x);
    }
    
    return pq.size();
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("CAU2.inp", "r")) {
        freopen("CAU2.inp", "r", stdin);
        freopen("CAU2.out", "w", stdout);
    }

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    cout << solve(a) << endl;
    sort(a.begin(), a.end());
    
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
10
51 12 27 96 85 24 7 8 5 10

Sort: 5 7 8 10 12 24 27 51 85 96 

51 85
12 24
27
96
5
7 8 10
*/