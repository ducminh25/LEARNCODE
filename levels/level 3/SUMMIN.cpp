#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base :: sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int minn = INT_MAX;
    int i, p;
    for (i = 1; i <= n - 1; ++i)
    {
        if (abs(arr[i] + arr[i + 1]) <= minn)
        {
            minn = abs (arr[i] + arr[i + 1]);
            p = i;
        }
    }
    cout << minn << endl;
    cout << p + 1 << " " << p + 2;
    return 0;
}