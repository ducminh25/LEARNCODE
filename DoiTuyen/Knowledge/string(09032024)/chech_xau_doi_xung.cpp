#include <bits/stdc++.h>
using namespace std;
bool checkPalindromeString(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

int main ()
{
    string s;
    getline(cin, s);
    if (checkPalindromeString(s)) cout<<"YES";
    else cout<<"NO";
    return 0;
}