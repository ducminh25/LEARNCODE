#include <bits/stdc++.h>
using namespace std;
int space_left(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (isspace(s[i])) {
      return i;
    }
  }
  return -1;
}
int space_right(string s) {
  for (int i = s.size() - 1; i >= 0; i--) {
    if (isspace(s[i])) {
      return i;
    }
  }
  return -1;
}


int main() {
  string s;
  getline (cin, s);
  int left = space_left(s);
  int right = space_right(s);
  cout << left << " " << right << endl;
  return 0;
}
