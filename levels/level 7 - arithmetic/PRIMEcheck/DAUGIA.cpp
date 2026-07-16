#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
    if (n < 2) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }

    return 1;
}

string toString(int n) {
    string res = "";
    while (n > 0) {
        res += n % 10 + '0';
        n /= 10;
    }

    return res;
}

bool checkPalin(int n) {
    string s = toString(n);
    for (int i = 0; i < s.size() / 2; ++i) {
        if (s[i] != s[s.size() - i - 1]) return 0;
    }

    return 1;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int l, r;
    cin >> l >> r;
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
        if(checkPrime(i) && checkPalin(i)) {
            cnt++;
            // cout << i << " ";
        }
    }
    cout << cnt << endl;

    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;
 
// bool isPrime(int n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (int i = 5; i * i <= n; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0) return false;
//     }
//     return true;
// }
 
// bool isPalindrome(int n) {
//     int reversed = 0, original = n;
//     while (n > 0) {
//         reversed = reversed * 10 + n % 10;
//         n /= 10;
//     }
//     return original == reversed;
// }
 
// int main() {
//     ios_base :: sync_with_stdio(false);
//     cin.tie(NULL); cout.tie(NULL);

//     int A, B;
//     cin >> A >> B;
//     int count = 0;
//     for(int i = A; i <= B; ++i) {
//         if(isPrime(i) && isPalindrome(i)) {
//             cout << i << " ";
//             count++;
//         }
//     }
//     cout << count << endl;
//     return 0;
// }
