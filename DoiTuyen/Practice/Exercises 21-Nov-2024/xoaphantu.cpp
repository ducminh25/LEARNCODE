#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    if(fopen("xoaphantu.INP", "r")) {
        freopen("xoaphantu.INP", "r", stdin);
        freopen("xoaphantu.OUT", "w", stdout);
    }
    
    int n, x;
    cin >> n >> x;
    
    vector<int> A(n);
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    
    int mindis = abs(A[0] - x);
    for (int i = 1; i < n; ++i)
        mindis = min(mindis, abs(A[i] - x));
    
    vector<int> res;
    for (int i = 0; i < n; ++i)
        if (abs(A[i] - x) != mindis)
            res.push_back(A[i]);

    for (int num : res)
        cout << num << " ";
    cout << endl;

    return 0;
}
