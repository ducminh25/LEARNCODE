/*#include <bits/stdc++.h>
using namespace std;

void genRand(int n) {
    srand(time(0));
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << rand() % 1000 << "\n";
    }
    cout << endl;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);
    int n;
    cin >> n;
    genRand(n);

    return 0;
}
*/
// Random numbers

// #include <bits/stdc++.h>
// #define endl '\n'
// using namespace std;

// int main() {
//     ios_base :: sync_with_stdio(false);
//     cin.tie(0); cout.tie(0);

//     freopen("test.out", "w", stdout);

//     cout << 1 << endl << 200000 << ' ' << 100000 << ' ' << 1 << endl;
//     for (int i = 1; i <= 200000; ++i) cout << 0;
        
//     return 0;
// }

/*
Hãy giúp tôi viết code sinh test ngẫu nhiên, với các yêu cầu sau:
- Khi code bắt đầu chạy, cho người dùng nhập vào một số T là số lượng test cần làm (có thể để người dùng sửa đổi T trong code cũng được, đỡ lằng nhằng).
- Với mỗi test, random một số t trong khoảng từ a đến b (a và b người dùng tự sửa ở trong code, với a < b).
- Với t dòng sau đó, in ra một số ngẫu nhiên từ c đến d (c và d người dùng tự sửa ở trong code, với c < d) và xuống dòng.
*/

#include <bits/stdc++.h>
#include <random>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T, a, b, c, d;
    cin >> T >> a >> b >> c >> d;

    mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<> dist(c, d);

    for (int i = 0; i < T; i++) {
        long long t = rand() % 10;
        cout << t << "\n";
        for (int j = 0; j < t; j++) {
            cout << dist(rng) << "\n";
        }
        cout << "\n";
    }

    return 0;
}