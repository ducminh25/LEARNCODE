#include <iostream>
#include <string>
using namespace std;
string replaceString(string s1, string s2, string s) {
    long long pos = 0;
    while ((pos = s.find(s1, pos)) != string::npos) {
         s.replace(pos, s1.length(), s2);
         pos += s2.length();
    }
    return s;
}

int main ()
{
    string s1, s2, s;
    getline (cin, s1);
    getline (cin, s2);
    getline (cin, s);
    cout << replaceString(s1, s2, s) << endl;
    return 0;
}