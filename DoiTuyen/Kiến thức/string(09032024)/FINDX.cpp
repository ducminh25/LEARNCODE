#include <iostream>
#include <string>

using namespace std;

int main() {
    char x;
    string s;
    cin >> x;
    cin.ignore();
    getline(cin, s); 

    int count = 0;
    string positions;

    for (size_t i = 0; i < s.length(); ++i) {
        if (s[i] == x) {
            count++;
            positions += to_string(i) + " ";
        }
    }

    cout << count << endl;
    cout << positions << endl;

    return 0;
}