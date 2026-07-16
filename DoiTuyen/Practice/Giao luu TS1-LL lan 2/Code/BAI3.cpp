#include<bits/stdc++.h>
using namespace std;
const int maxn = 100001;
int n, k;
int a[maxn];
bool ok[maxn];
long long res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // freopen("Bai3.INP","r",stdin);
    // freopen("Bai3.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (ok[i]) continue;
        int j = i;
        vector<int> vals;
        while (!ok[j]) {
            vals.push_back(a[j]);
            ok[j] = true;
            j = (j + k - 1) % n+1;
        }
        sort(vals.begin(), vals.end());
        int median = vals[vals.size() / 2];
        for (int l=0;l<vals.size();l++)
            res += abs(vals[l] - median);
    }
    cout << res;

}

