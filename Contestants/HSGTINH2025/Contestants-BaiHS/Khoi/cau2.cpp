#include <bits/stdc++.h>
#define ll long long
const int N = 1e6 + 2;
using namespace std;

int n, k, a[N], ma, ans, b[N];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("cau2.inp", "r")){
        freopen("cau2.inp", "r", stdin);
        freopen("cau2.out", "w", stdout);
    }

    cin >> n >> k;

    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
        ma = max(ma, a[i]);
    }

    if (k == 0){
        for (int i = 1; i <= n; i++){
            ans += (ma - a[i]);
        }
    }
    else if(k == -1){
        bool kt = false;

        for (int i = 1; i <= n; i++){
            if (a[1] >= a[i] && !kt){
                ans += (a[1] - a[i]);
            }
            else{
                ans += (ma - a[i]);
                kt = true;
            }
        }
    }
    else{
        sort(b + 1, b + n + 1);

        int x = b[n / 2 + 1];
        bool kt = false;

        for (int i = 1; i <= n; i++){
            if (x >= a[i] && !kt){
                ans += (x - a[i]);
            }
            else{
                ans += (ma - a[i]);
                kt = true;
            }
        }
    }

    cout << ans;
    return 0;
}
