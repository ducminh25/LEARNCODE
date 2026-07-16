#include <bits/stdc++.h>
#define ll long long
#define str string
using namespace std;
ll dc[1000005],dw[1000005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (fopen("COW.inp","r"))
    {
        freopen("COW.inp","r",stdin);
        freopen("COW.out","w",stdout);
    }
    ll n;
    cin>>n;
    str s;
    cin>>s;
    s=" "+s;
    ll kq=0;
    if (n<255){
        for (ll i=1;i<=n-2;i++){
                if (s[i]=='C'){
            for (ll j=i+1;j<=n-1;j++){
                if (s[j]=='O'){
                    for (ll k=j+1;k<=n;k++){
                        if (s[k]=='W') kq++;
                    }
                }
            }
        }
        }
        cout<<kq;
    }
    else{
        for (ll i=1;i<=n;i++){
            if (s[i]=='C') dc[i]=dc[i-1]+1;
            else dc[i]=dc[i-1];
        }
        for (ll i=n;i>=1;i--){
            if (s[i]=='W') dw[i]=dw[i+1]+1;
            else dw[i]=dw[i+1];
        }
        for (ll i=2;i<=n-1;i++){
            if (s[i]=='O') kq+=dc[i-1]*dw[i+1];
        }
        cout<<kq;
    }


    return 0;
}

