/* #include <bits/stdc++.h>
using namespace std;
int main ()
{
    freopen ("string.inp", "r", stdin);
    freopen ("string.out", "w", stdout);
    while (true)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1 == "END" && s2 == "END") break;

        sort (s1.begin (), s1.end());
        sort (s2.begin (), s2.end ());

        if (s1 == s2)
            cout << "same" << endl;
        else cout << "different" << endl;
    }

    return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    // freopen("string.inp", "r", stdin);
    // freopen("string.out", "w", stdout);
    
    string s1, s2;
    
    while (cin >> s1 >> s2) 
    {
        if (s1 == "END" && s2 == "END") 
            break;
        
        int freq1[256] = {0}, freq2[256] = {0};
        
        for (char c : s1) 
            freq1[c]++;
        for (char c : s2) 
            freq2[c]++;
        
        bool same = true;
        for (int i = 0; i < 256; i++) {
            if (freq1[i] != freq2[i]) {
                same = false;
                break;
            }
        }
        
        if (same)
            cout << "same" << endl;
        else
            cout << "different" << endl;
    }
    
    return 0;
}