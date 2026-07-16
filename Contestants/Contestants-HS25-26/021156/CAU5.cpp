#include <bits/stdc++.h>
#define N int(1e5)
using namespace std;
int n,k,x;
int a[N+5];
multiset<int>se;
vector<int>b[N+6];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CAU5.INP","r",stdin);
    freopen("CAU5.OUT","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    se.insert(a[1]);
    int h=1;
    b[h].push_back(a[1]);
    long long t=a[1];
    for(int i=2;i<=n;i++)
    {
        auto vt=se.upper_bound(a[i]);
        //vt--;
        if(vt!=se.begin())
        {
            vt--;
            se.erase(vt);
            se.insert(a[i]);
        }
        else
        {
            se.insert(a[i]);
            h++;
            b[h].push_back(a[i]);
            t+=a[i];
        }
    }
    cout<<t<<'\n';
    return 0;
}
