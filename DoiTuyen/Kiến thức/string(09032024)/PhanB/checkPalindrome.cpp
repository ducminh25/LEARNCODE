#include <bits/stdc++.h>
using namespace std;
//checkPalindrome
bool checkPalindrome(string s)
{
    for (int i = 0; i < s.size() / 2; i++)
    {
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie (NULL); cout.tie (NULL);
    string s;
    getline (cin,s);
    if (checkPalindrome(s)) cout << "YES";
    else cout << "NO";
    return 0;
}