#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    int n; cin >> n;
    map <string, int> cnt;
    while (n--)
    {
        int type;
        string name;
        cin >> type >> name;

        if (type == 1) cnt[name]++;
        else cout << cnt[name] << endl;
    }

    return 0;
}