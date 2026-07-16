#include <bits/stdc++.h>
#define int long long
const int N = 1e6;
using namespace std;
int a[N+6],b[N+6],n,m;
void sub1(){
    int dem=0;
    for (int i=1;i<=n;i++){
        bool ok=true;
        for (int j=1;j<=m;j++){
            if (__gcd(a[i],b[j])!=1){
                ok=false;
                break;
            }
        }
        if (ok)dem++;
    }
    cout<<dem;
}
int dx[N+6];
void sub2(){
    for (int i=1;i<=m;i++){
        dx[b[i]]==1;
    }
    int dem=0;
    for (int j=1;j<=n;j++){
        if (dx[a[j]]==0) dem++;
    }
    cout<<dem;
}
int32_t main(){
    // Calm down and stay cool
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    freopen("cau3.inp","r",stdin);
    freopen("cau3.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int j=1;j<=m;j++) {
        cin>>b[j];
    }
    if (n<=1003 && m<=1003) sub1();
    else  sub2();
    return 0;
}
