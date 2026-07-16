#include <bits/stdc++.h>

using namespace std;
int n,ans = 0;
int cal(int x)
{
    if (x == 1) return 1;
    int i = 2;
    int count_div = 1; ///luu so uoc cua x
    while (i*i <= x)
    {
        int d = 0; /// luu so mu cua so nguyen to i
        while (x % i == 0)
        {
            d++;
            x = x/i;
        }
        i++;
        count_div *= (d+1);
    }
    if (x > 1) count_div *= 2;
    return count_div;
}
int main()
{
    freopen("bsbb.inp","r",stdin);
    freopen("bsbb.out","w",stdout);
    cin >> n;
    for (int i=1; i<n; i++)
        ans += cal(i);
    cout << ans;
    return 0;
}
