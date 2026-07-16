#include <iostream>
#include <string>
using namespace std;

string encodeString(string s) {
    string result = "";
    for (char &c : s) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + 5) % 26 + base;
        }
        result += c;
    }
    return result;
}

string decodeString(string s) {
    string result = "";
    for (char &c : s) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base - 5 + 26) % 26 + base;
        }
        result += c;
    }
    return result;
}

int main() {
    int t;
    cin >> t;

    int options[t];
    string strings[t];

    for (int i = 0; i < t; i++) {
        cin >> options[i] >> strings[i];
    }

    for (int i = 0; i < t; i++) {
        if (options[i] == 0) {
            cout << encodeString(strings[i]) << endl;
        } else if (options[i] == 1) {
            cout << decodeString(strings[i]) << endl;
        } else {
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}