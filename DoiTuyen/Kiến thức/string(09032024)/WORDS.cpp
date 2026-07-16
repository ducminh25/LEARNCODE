#include <iostream>
#include <string>
using namespace std;
string s, kq; int d;
int main(){
    getline(cin,s);
    s = " " + s;
    kq = "";
    for (int i = 0; i < s.length(); i++)
	{
        if (s[i] != ' ' && s[i-1] == ' ')
        {
        	d++;
		}
        if (s[i] != ' ')
        {
        	kq += s[i];
		}
        if (s[i] == ' ' && s[i-1] != ' ')
        {
        	kq += "\n";
		}
    }
    cout << d << kq;
}