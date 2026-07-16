#include <iostream>
#include <string>
using namespace std;
int main ()
{
    string st;
    getline (cin, st);
    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] == 'a' or st[i] == 'A')
        {
            st.replace (i, 1, "");
        }
    }
    cout << st;
    return 0;
}