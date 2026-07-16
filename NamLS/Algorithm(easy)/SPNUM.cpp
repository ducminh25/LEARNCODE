#include <bits/stdc++.h>
using namespace std;

bool is_prime[10000005];
const int maxn = 10000005;
void sieve()
{
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= maxn; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= maxn; j += i)
                is_prime[j] = false;
}

// bool isPrime(int n)
// {
//     if (n < 2)
//         return false;
//     if (n == 2 || n == 3)
//         return true;
//     if (n % 2 == 0 || n % 3 == 0)
//         return false;
//     int sq = sqrt(n);
//     for (int i = 5; i <= sq; i += 6)
//     {
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     }

//     return true;
// }

// __builtin_popcount(n)
int cnt1bit(int n)
{
    int cnt = 0;
    while (n)
    {
        cnt += n & 1; // Kiểm tra xem bit ở địa chỉ 0 có phải là 1 hay không. Nếu có, cnt++
        n >>= 1;      // Dịch chuyển các bit của n sang bên phải 1 vị trí
    }

    return n;
}

// int createNext(int n) {
//     int c = n & -n;
//     int r = n + c;
//     int ones = __builtin_popcount(n);
//     int pos = __builtin_ctz(c); // trả về số lượng bit 0 từ trái sang phải trong giá trị nhị phân của x trước khi gặp bit 1 đầu tiên
//     n = (((r ^ n) >> 2) / c) | r;
//     while(cnt1bit(n) != ones){
//         n--;
//     }
//     return n;
// }

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    if (fopen("SPNUM.inp", "r")) {
        freopen("SPNUM.inp", "r", stdin);
        freopen("SPNUM.out", "w", stdout);
    }
    sieve();
    int n, k, cnt = 0;
    cin>>n>>k;
     for(int i = 1;i<=n;++i){
         if(__builtin_popcount(i) == k && is_prime[i]) cnt++;
     }
     cout<<cnt;
    return 0;
}