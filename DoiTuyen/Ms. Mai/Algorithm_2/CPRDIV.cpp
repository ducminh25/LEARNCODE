// Tổ hợp chập m của n phần tử
#include <bits/stdc++.h>
using namespace std; 
int c [100000] = {0}; // đếm ước ngto từ m+1 tới n
int c1 [100000] = {0}; // đếm ước ngto từ 2 tới n-m

int main() { 
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);

    if(fopen("CPRDIV.inp", "r")) {
        freopen ("CPRDIV.inp", "r", stdin);
        freopen ("CPRDIV.out", "w", stdout);
    }

    int n, m; 
    cin >> n >> m; 

    for (int i = m + 1; i <= n; ++i) {
        int t = i; 
        int k = 2; 
        while (t != 1) { 
            if (t % k == 0) { 
                c [k]++; 
                t /= k; 
            }
            else k++; 
        }
    } 
    
    for (int i = 2; i <= n - m; i++) { 
        int t = i; 
        int k = 2; 
        while (t != 1) { 
            if (t % k == 0) { 
                c1 [k]++; 
                t /= k; 
            } 
            else k++; 
        }
    }

    int d = 0;
    for(int i = 2; i <= 100000; ++i) 
        if(c[i] > c1[i]) d++;
    cout << d; 

    return 0;
}




// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// const int MAX_N = 60000;

// ll cnt[MAX_N + 1];

// void ana(ll n, ll k) {
//     for (int i = 2; i * i <= n; i++) {
//         if (cnt[i] == 0) {
//             while (n % i == 0) {
//                 cnt[i] += k;
//                 n /= i;
//             }
//         }
//     }
//     if (n > 1) {
//         cnt[n] += k;
//     }
// }

// ll m, n, res = 0;

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     for (int i = 1; i <= MAX_N; i++) {
//         cnt[i] = 0;
//     }
//     cin >> n >> m;
//     if (n <= m) {
//         cout << 0;
//         return 0;
//     }

//     for (int i = m + 1; i <= n; i++) {
//         ana(i, 1);
//     }
//     for (int i = 1; i <= n - m; i++) {
//         ana(i, -1);
//     }
//     for (int i = 1; i <= MAX_N; i++) {
//         if (cnt[i] > 0) {
//             res++;
//         }
//     }
//     cout << res;

//     return 0;
// }
