#include <bits/stdc++.h>

using namespace std;


int main() {
//  string s;
//  cin >> s;
//
//  int pos = s.find('/');
//  if (pos == string::npos) {
//    cout << "INVALID" << endl;
 //   return 1;
 // }

//  int a = stoi(s.substr(0, pos));
 // int b = stoi(s.substr(pos + 1));
  long long a,b;
  cin>>a>>b;
  if (b==0)
  {
      cout<<"INVALID";
     return 0;
  }

//  long long a,b;
//  cin>>a>>b;
  if (b==0) return 0;
  int tu = 1, mau = 1;
  if (a<0)
  {
      a = -a;
      tu = -1;
  }
  if (b<0)
  {
      b = -b;
      mau = -1;
  }
  int ucln = __gcd(a,b);
  if (a%__gcd(a,b)==0) a /= ucln;
  if (b%__gcd(a,b)==0) b /= ucln;

  if (a*tu*b*mau >= 0) cout << abs(a*tu) << "/" << abs(b*mau) << endl;
  else
  {
      if (b*mau < 0 && a*tu >= 0) cout << -a*tu << "/" << abs(b*mau) << endl;
      else cout << a*tu << "/" << abs(b*mau) << endl;
  }

  return 0;
}
