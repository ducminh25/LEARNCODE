#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int n;
    cin >> n;
    stack <int> a;
    int b;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        a.push(b);
    }

    while (a.size())
    {
        cout << a.top() << endl;
        a.pop();
    }

    return 0;
}