#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int spf[N]; // spf[i] là ước nguyên tố nhỏ nhất của i
int c[N]; // cnt[i] là số lượng ước của i
bool isPrime[N]; // isPrime[i] là true nếu i là số nguyên tố
int prime[N]; // prime[i] là số nguyên tố thứ i
int top = 1; // số lượng số nguyên tố

bool nt (int n)
{
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return false;
    }
    return true;
}
void sieve() {
    memset(spf, 0, sizeof(spf));
    memset(prime, 0, sizeof(prime));

    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            prime[top++] = i;
            isPrime[i] = true;
        }
        for (int j = 1; j <= top && prime[j] * i < N; j++) {
            spf[prime[j] * i] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }

    for (int i = 1; i < N; i++)
    {
        
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // freopen ("uocnto.inp", "r", stdin);
    // freopen ("uocnto.out", "w", stdout);

    sieve();

    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int res = 0;
        for (int i = a; i <= b; i++) {
            if (isPrime[c[i]]) res++;
        }
        cout << res << '\n';
    }
    return 0;
}



/*
for(int i=1;i*i<=n;i++)
{
    if(n%i==0)
        {
        if(i!=n/i)
            res+=2;
        else
            res++;
        }
}
for(int i=1;i<=1000000;i++)
{
    if(nt[demuoc(i)]==0)
    {
        m++;
        d[m]=d[m-1]+1;
    }
    else
    {
        m++;
        d[m]=d[m-1];
    }
    cout<<d[b]-d[a-1];
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) count++;
            else count += 2;
        }
    }
    return count;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    // freopen ("uocnto.inp", "r", stdin);
    // freopen ("uocnto.out", "w", stdout);
    
    int T;
    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;
        int count = 0;
        for (int i = a; i <= b; i++) {
            if (isPrime(countDivisors(i))) count++;
        }
        cout << count << endl;
    }
    return 0;
}

*/

/*
#@include <bits/stdc++.h>
using namespace std;

*/