#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
ll n;
string s;
ll ow[1000009], w[1000009], demo=0, ans=0;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen("COW.inp","r")){
        freopen("COW.inp","r",stdin);
        freopen("COW.out","w",stdout);
    }
    cin>>n;
    cin>>s;
    s=' '+s;
    w[n+1]=0;
    ow[n+1]=0;
    for(ll i=n; i>0; i--){
        w[i]=w[i+1];
        ow[i] = ow[i+1];
        if(s[i] == 'W'){
            w[i]++;
            demo=0;
        }
        else if(s[i] == 'O'){
            ow[i]+=w[i];
        }
    }
    for(ll i=1; i<n; i++){
        if(s[i] == 'C'){
            ans+=ow[i+1];
        }
    }
    cout<<ans;
    return 0;
}
/*
10
CCOOWOWCCW
*/




