#include <iostream>
using namespace std;
int main ()
{
    //split a string
    string s;
    getline (cin, s);
    string delimiter;
    getline (cin, delimiter);
    if (s.find(delimiter) != string::npos)
    {
        string token = s.substr(0, s.find(delimiter));
        cout << token;
    }
    else cout << "NPOS string";
    return 0;
}
