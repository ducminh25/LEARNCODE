#include <bits/stdc++.h>

using namespace std;

int n,a[100000];
string s;

void ReadData()
{
    cin >> n;
    cin.ignore();
    getline (cin, s);
}

void solve()
{
    if(n>26)
    {
        cout<< "-1";
        return;
    }
    for(int i=0;i<n;++i)
        a[int(s[i])]++;
    int cnt=0;
    for(int i=97;i<123;++i)
        if(a[i]>1)
            cnt=cnt+(a[i]-1);
    cout<<cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ReadData();
    solve();
    return 0;
}
