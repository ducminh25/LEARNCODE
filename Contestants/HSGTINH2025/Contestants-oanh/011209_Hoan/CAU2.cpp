#include <bits/stdc++.h>
using namespace std;
int n,k,a[1000006],t=INT_MIN,b,c,d;
long long tong=0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CAU2.inp","r",stdin);
    freopen("CAU2.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        t=max(t,a[i]);
    }
    if(k==0) {
        for(int i=1;i<=n;i++) {
            tong+=(t-a[i]);
        }
        cout<<tong;
        return 0;
    }
    if(k==-1) {
        int m=a[1];
        for(int i=2;i<=n;i++) {
            if(m<a[i]) m=t;
            tong+=(m-a[i]);
        }
        cout<<tong;
        return 0;
    }
    for(int i=1;i<=n;i++) {
        if(a[i]==t) break;
        b=max(b,a[i]);
    }
    for(int i=1;i<=n;i++) {
        if(a[i]==b) break;
        c=max(c,a[i]);
    }
    if(t-b>=b-c) d=b;
    else d=c;
    for(int i=1;i<=n;i++) {
        if(d<a[i]) d=t;
        tong+=(d-a[i]);
    }
    cout<<tong;
    return 0;
}
