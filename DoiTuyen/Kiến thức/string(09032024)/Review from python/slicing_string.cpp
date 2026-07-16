//slice a string
#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string s;
    getline(cin, s);
    int start, end;
    cin >> start >> end;
    cout << s.substr(start, end - start + 1);
}