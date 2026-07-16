#include <bits/stdc++.h>
using namespace std;
int main ()
{
    // freopen ("NGOAC.INP", "r", stdin);
    // freopen ("NGOAC.OUT", "w", stdout);
    int balance = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s [i] != '(' && s [i] != ')') 
        {
            cout << "KHONG HOP LE";
            return 0;
        }

        if (s[i] == '(')
            balance++;
        else
            balance--;
        if (balance < 0)
            break;
    }
    if (balance == 0)
        cout << "DUNG";
    else
        cout << "KHONG DUNG";
    
    return 0;
}

