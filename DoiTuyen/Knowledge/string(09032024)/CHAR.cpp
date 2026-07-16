#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen ("CHAR.inp","r",stdin);
    freopen ("CHAR.out","w",stdout);
    
    string s;
    getline(cin, s);

    int count[26] = {0};

    for (char c : s) {
        if (isalpha(c)) //kiểm tra xem c có thuộc bảng chữ cái hay không
        { 
            c = tolower(c);
            count[c - 'a']++;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (count[i] > 0) {
            cout << char (i + 'a')<< " " << count[i] << endl;
        }
    }

    return 0;
}