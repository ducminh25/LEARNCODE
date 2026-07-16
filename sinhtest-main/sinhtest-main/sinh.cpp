#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

#define lli long long

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    // Dùng seed có độ ngẫu nhiên cao để tránh trùng khi chạy nhanh nhiều lần
    auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
    rnd.setSeed(seed);

    // Đọc tham số đầu vào
    lli g1 = argc >= 2 ? stoll(argv[1]) : 10;
    lli g2 = argc >= 3 ? stoll(argv[2]) : g1;

    // Sinh ngẫu nhiên n trong [g1, g2]
    lli n = rnd.next(g1, g2);
    cout << n << "\n";

    for (long long i = 1; i <= n; ++i) {
        int a = rnd.next(1000, 10000);
        cout << a << " ";
        int b = rnd.next(1000, 10000);
        cout << b << " ";
    }
    cout << endl;
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
    // string number = "0123456789";

    // string x, y;
    // for (int i = 0; i < len; i++) {
    //     char c = number[rnd.next(0, (int)number.size() - 1)];
    //     x.push_back(c);
    // }
    // for (int i = 0; i < len; i++) {
    //     char c = number[rnd.next(0, (int)number.size() - 1)];
    //     y.push_back(c);
    // }
    // cout << x << endl << y << endl;
    return 0;
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