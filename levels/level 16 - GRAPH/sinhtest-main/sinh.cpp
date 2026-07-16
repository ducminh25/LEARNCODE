#include <bits/stdc++.h>
#include "testlib.h"
#include <chrono>
using namespace std;

int main(int argc, char* argv[]) {
    // Use with numbers
    registerGen(argc, argv, 1);  // version = 0 or 1

    // Create a seed from clock
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    rnd.setSeed(seed);  // set seed

    long long g1 = argc >= 2 ? stoll(argv[1]) : 10;
    long long g2 = argc >= 3 ? stoll(argv[2]) : g1;
    long long n = rnd.next(g1, g2);

    cout << n << " ";
    long long m = rnd.next(1, 100000);
    cout << m << " ";
    long long s = rnd.next(1LL, n);
    cout << s << endl;
    for (int i = 0; i < m; ++i) 
        cout << rnd.next(1LL, n) << " " << rnd.next(1LL, n) << endl;
    
    // long long a = 1000; // from
    // long long b = 50000; // to
    // for (int i = 1; i <= n; i++) {
    //     cout << rnd.next(a, b) << " " 
    //          << rnd.next(a, b) << "\n";
    // }
    return 0;

    // // Use with strings
    // registerGen(argc, argv, 1);

    // // Seed with miliseconds
    // auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    // rnd.setSeed(seed);

    // // g1 = min length, g2 = max length
    // long long g1 = argc >= 2 ? stoll(argv[1]) : 1;
    // long long g2 = argc >= 3 ? stoll(argv[2]) : g1;

    // // random length
    // int len = rnd.next((int)g1, (int)g2);

    // string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // tập ký tự

    // string s;
    // for (int i = 0; i < len; i++) {
    //     char c = alphabet[rnd.next(0, (int)alphabet.size() - 1)];
    //     s.push_back(c);
    // }

    // cout << s;

    // return 0;
}

   //  lli m = sqrt(n);
   //  if (m < 5) m = 2 * m;
   //  lli q = rnd.next(2ll, m);
   //  lli x, s = 0;
   //  cout << n << " " << q << endl;
   //  for (int i = 1; i <= n; i++) {
   //      x = rnd.next(1ll, m);
   //      s += x;
   //      cout << x;
   //      if (i == n)
   //          cout << endl;
   //      else
   //          cout << " ";
   //  }
   //  for (int i = 1; i <= q; i++) cout << rnd.next(1ll, s - 1) << endl;