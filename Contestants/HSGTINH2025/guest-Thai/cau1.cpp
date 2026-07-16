#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    // Calm down and stay cool
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    freopen("cau1.inp","r",stdin);
    freopen("cau1.out","w",stdout);

    int l,r;
    cin>>l>>r;
    int dem=0;
    for (int i=l;i<=r;i++){
        if ((i-1)%2==0){
            dem++;
        }
    }
    cout<<dem;
    return 0;
}
