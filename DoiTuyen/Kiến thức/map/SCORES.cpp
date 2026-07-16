#include <bits/stdc++.h>
using namespace std;

map <string, int> m;
int q;

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> q;
    while (q--)
    {
        int type, p;
        string name;
        cin >> type;

        if (type == 1)
        {
            cin >> name >> p;
            m[name] += p;
        }
        else if (type == 2)
        {
            cin >> name;
            m.erase (name);
        }
        else
        {
            cin >> name;
            cout << m[name] << endl;
        }
    }

    return 0;
}