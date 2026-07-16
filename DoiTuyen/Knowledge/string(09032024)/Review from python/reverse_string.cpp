#include <bits/stdc++.h>
using namespace std;

string reverseWords(string const &s) {
    stack<string> words;
    string result;
    string word;

    for (char ch : s) {
        if (ch == ' ') {
            if (!word.empty()) {
                words.push(word);
                word.clear();
            }
        } else {
            word += ch;
        }
    }

    if (!word.empty()) {
        words.push(word);
    }

    while (!words.empty()) {
        result += words.top();
        words.pop();
        if (!words.empty()) result += " ";
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    string s;
    getline (cin, s);
    string reversed = reverseWords(s);
    cout << reversed << endl;
    return 0;
}