#include <bits/stdc++.h>
using namespace std;
int l,r,d=0;
bool kt(int x)
{
    if(x<2) return false;
    for(int i=2;i*i<=x;i++) {
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("CAU1.inp","r",stdin);
    freopen("CAU1.out","w",stdout);
    cin>>l>>r;
    for(int i=l;i<r;i++) {
        for(int j=i+1;j<=r;j++) {
            if(kt(j*j-i*i)) d++;
        }
    }
    cout<<d;
    return 0;
}
