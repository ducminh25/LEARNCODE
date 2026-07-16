#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    if(fopen("XDB.inp", "r")) {
        freopen("XDB.inp", "r", stdin);
        freopen("XDB.out", "w", stdout);
    }
    
    string a, b, s;
    getline(cin, a);
    getline(cin, b);
    getline(cin, s);

    unordered_set<char> yen_chars(a.begin(), a.end());
    unordered_set<char> dinh_chars(b.begin(), b.end());

    int result = 0;
    int yen_count = 0, dinh_count = 0;
    int left = 0;

    for (int right = 0; right < s.length(); right++) {
        if (yen_chars.count(s[right])) yen_count++;
        else if (dinh_chars.count(s[right])) dinh_count++;
        else if (s[right] != ' ') {
            // Reset counts if we encounter a character not in either set
            yen_count = dinh_count = 0;
            left = right + 1;
            continue;
        }

        while (yen_count != dinh_count && left <= right) {
            if (yen_chars.count(s[left])) yen_count--;
            else if (dinh_chars.count(s[left])) dinh_count--;
            left++;
        }

        if (yen_count == dinh_count && yen_count > 0) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}