#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000006],b[1000006],k,d=0;
long long t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CAU3.inp","r",stdin);
    freopen("CAU3.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) {
        cin>>b[i];
        if(i==1) k=b[i];
        else {
            k=(k*b[i])/(__gcd(k,b[i]));
        }
    }
    for(int i=1;i<=n;i++) {
        if(__gcd(k,a[i])==1) d++;
    }
    cout<<d;

    return 0;
}
