#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100001;
int n, k;
int A[MAX_N];
bool vis[MAX_N];
long long ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("Bai3.INP","r",stdin);
    freopen("Bai3.OUT","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> A[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        int j = i;
        vector<int> vals;
        while (!vis[j]) {
            vals.push_back(A[j]);
            vis[j] = true;
            j = (j + k - 1) % n+1;
        }
        sort(vals.begin(), vals.end());
        int median = vals[vals.size() / 2];
        for (int i=0;i<vals.size();i++)
            ans += abs(vals[i] - median);
    }
    cout << ans;

}

