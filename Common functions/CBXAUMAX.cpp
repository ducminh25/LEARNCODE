#include <bits/stdc++.h>
using namespace std;
string a [1000];
int n;

void input () {
    cin >> n;
    string s;
    getline (cin, s);
    for (int i = 0; i < n; i++) {
        getline (cin, a [i]);
    }
}

void largestString () {
    int max = 0;
    for (int i = 1; i < n; i++) {
        if (a [i] > a [max]) max = i;
    }
    
    cout << a [max] << endl;
}

void longestString () {
    int max = 0;
    for (int i = 1; i < n; ++i) {
        if (a [i].length () > a [max].length ()) max = i;
    }

    cout << a [max] << endl;
}

int main () {
    input ();
    largestString ();
    longestString ();
    return 0;
}
