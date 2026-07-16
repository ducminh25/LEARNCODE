//check if substring in a string
#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string S, s;
    getline (cin, S);
    getline (cin, s);
    if (S.find(s) != string::npos)
    {
        cout << "YES";
    }
    else cout << "NO";
    return 0;
}