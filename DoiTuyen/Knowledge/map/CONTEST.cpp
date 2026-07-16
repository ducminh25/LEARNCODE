#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 1;
int C, P, S;
map <string, int> score;
map <string, int> id;
string candidate [N];
int ans [N];

int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    cin >> C >> P >> S;
    for (int i = 1; i <= C; ++i)
    {
        cin >> candidate [i];
        id [candidate [i]] = i;
    }
    
    for (int i = 1; i <= P; ++i)
    {
        string s;
        int p;
        cin >> s >> p;
        score [s] = p;
    }
    for (int i = 1; i <= S; ++i)
    {
        string c, p, s;
        cin >> c >> p >> s;
        if (id.find (c) == id.end ()) continue;
        if (s == "AC") ans [id [c]] += score [p];
    }

    for (int i = 1; i <= C; ++i)
    {
        cout << candidate [i] << " " << ans [i] << endl;
    }

    return 0;
}
