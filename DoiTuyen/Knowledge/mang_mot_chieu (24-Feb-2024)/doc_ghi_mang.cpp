#include <bits/stdc++.h>
using namespace std;

int m,n;
int A[20];
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("docmang.inp", "r", stdin);
    freopen("docmang.out", "w", stdout);
    cin>>n;
    for (int i = 0; i<n; i++)
    {
        cin>>A[i];
    }

    for (int j = 0; j<n; j++) cout<<A[j]<<" ";
    return 0;
}