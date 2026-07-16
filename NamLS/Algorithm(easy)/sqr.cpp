#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define all (v)(v).begin(), (v).end()
#define compress(v) \
    sort(all(v));   \
    (v).erase(compress(all(v)), (v).end());
#define task "sqr"

const long long N = 1e6 + 5;
bool prime[N], ok;
long long n;
long long s[N], cnt[N], Count;

// small sieve
void sieve() {
    memset(prime, true, sizeof prime);
    prime[1] = false;
    for (long long i = 2; i < N; ++i) {
        if (!prime[i]) continue;
        for (long long j = i; j < N; j += i) {
            prime[j] = false;
            s[j] = i;
        }
    }
}

void compute(long long x) {
    while (x != 1) {
        cnt[s[x]]++;
        if (cnt[s[x]] & 1)
            Count++;
        else
            Count--;
        ok = (Count == 0);
        x /= s[x];
    }
}

int main() {
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen(task ".INP", "r")) {
        freopen(task ".INP", "r", stdin);
        freopen(task ".OUT", "w", stdout);
    }

    sieve();
    ok = true;
    cin >> n;
    while (n--) {
        long long x;
        cin >> x;
        compute(x);
        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}

/*
Minh và Tiến cùng chơi một trò chơi với các số nguyên như sau:
- Ban đầu, Minh có một số P = 1.
- Có N lượt chơi, ở mỗi lượt, Tiến đọc một số nguyên K, nhiệm vụ của Minh là phải nhân số P với K, được bao nhiêu lại gán cho P, sau đó trả lời ngay số P hiện tại có phải số chính phương hay không. Học dốt toán nên Minh cần các bạn lập chương trình trả lời giúp.

Input
- Dòng đầu tiên chứa số nguyên N (1 <= N <= 5*10^5).
- Tiếp theo là N dòng, mỗi dòng ghi một số nguyên là số mà Tiến đã đọc. Các số nguyên này nằm giữa 1 và 10^6.

Output: gồm N dòng là kết quả mỗi lượt chơi. Ghi "YES" nếu kết quả là số chính phương và "NO" trong trường hợp ngược lại.

Ví dụ:
INPUT:
7
2
3
6
15
35
21
64
--> OUTPUT:
NO
NO
YES
NO
NO
YES
YES
*/