/*
#include <iostream>
#include <string>
using namespace std;
void chuanhoaten(string &name) {
    bool capitalizeNext = true;
    for (char &c : name) {
        if (isspace(c)) {
            capitalizeNext = true;
        } else {
            if (capitalizeNext) {
                c = toupper(c);
                capitalizeNext = false;
            } else {
                c = tolower(c);
            }
        }
    }
}

int main() {
    string name;
    getline(cin, name);
    chuanhoaten(name);
    cout << name << endl;
    return 0;
}
*/
/*
#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    //freopen("NAME.INP","r",stdin);
    //freopen("NAME.OUT","w",stdout);
    getline(cin,s);
    while (s.find("  ") !=string::npos)
    {
        int k = s.find("  ");
        s.erase(k,1);
    }
    if (s[0] == ' ') s.erase(0,1);
    if (s[s.length() - 1] == ' ') s.erase(s.length()-1,1);
    for (int i=0; i<=s.length()-1; i++)
    if ('A' <= s[i] && s[i] <= 'Z') s[i] = s[i] + 32;
    s[0] = s[0] - 32;
    for (int i=0; i<=s.length()-1; i++)
    if (s[i] == ' ') s[i+1] = s[i+1] - 32;
    cout << s;
    return 0;
}
*/
#include <iostream>
#include <string>

using namespace std;

string chuanHoa(string s) {
  // Loại bỏ dấu cách thừa
  while (s.find("  ") != string::npos) {
    s.replace(s.find("  "), 2, " ");
  }

  // Viết hoa chữ cái đầu mỗi từ
  for (int i = 0; i < s.size(); i++) {
    if (i == 0 || s[i - 1] == ' ') {
      if (s[i] >= 'a' && s[i] <= 'z') {
        s[i] -= 32;
      }
    } else {
      if (s[i] >= 'A' && s[i] <= 'Z') {
        s[i] += 32;
      }
    }
  }

  return s;
}

int main() {
  string s;
  getline(cin, s);

  string sChuanHoa = chuanHoa(s);

  cout << sChuanHoa << endl;

  return 0;
}
