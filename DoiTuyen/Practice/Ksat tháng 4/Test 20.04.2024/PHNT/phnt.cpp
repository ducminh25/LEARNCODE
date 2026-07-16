#include <bits/stdc++.h>

using namespace std;
int n, ans;
string s;
bool check(int k)
{
    set <string> Set; ///cau truc du lieu
    for (int i=k; i<=n; i++)
    {
        string x = s.substr(i-k,k);
        if (Set.find(x) != Set.end())
            return false;
        Set.insert(x);
    }
    return true;
}
int main()
{
    freopen("phnt.inp","r",stdin);
    freopen("phnt.out","w",stdout);
    cin >> n;
    cin >> s;
    int l = 1, r = n;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ans;
    return 0;
}
