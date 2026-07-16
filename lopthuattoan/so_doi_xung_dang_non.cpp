#include <bits/stdc++.h>
using namespace std;

bool tangdan(long long x)
{
    long long y = x % 10;
    x = x/10;
    long long z;
    while (x>0)
    {
        z = x % 10;
        x = x/10;
        if (z>=y) return false;
        y=z;
    }
    return true;
}
long long dx1 (long long x)
{
    long long y = x/10;
    while (y>0)
    {
        x = x*10 + (y%10);
        y = y/10;
    }
    return x;
}
long long dx2 (long long x)
{
    long long y = x;
    while (y>0)
    {
        x = x*10 + (y%10);
        y = y/10;
    }
    return x;
}

long long n,k,res;
int main ()
{
    cin>>n;
    for (long long i = 1; i<100000; i++)
    {
        if (tangdan(i) == true)
        {
            k = dx1(i);
            if (k>n) break;
            res++;
            k = dx2(i);
            if (k <= n) res++;
        }
    }
    cout<<res;
    return 0;
}

// Số đối xứng dạng nón (số đối xứng, các chữ số tăng dần từ trái đến giữa và từ phải đến giữa)
