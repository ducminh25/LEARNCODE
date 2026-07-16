#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline (cin, s);

  int count[10] = {0};
  for (char c : s) {
    if (isdigit(c)) {
      count[c - '0']++;
    }
  }

  for (int i = 0; i < 10; i++) {
    cout << count[i] << " ";
  }

  return 0;
}
