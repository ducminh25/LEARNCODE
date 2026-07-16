#include<bits/stdc++.h>
using namespace std;
#define NAME "CAU1"
#define ll long long
#define N 1000100
ll l,r,kq=0;
bool a[N+5];
void snt(ll n){
    fill(a+1,a+n+1,1);
    a[0]=a[1]=0;
    for(int i=2;i*i<=n;i++){
        if(a[i]){
            for(int j=i*i;j<=n;j+=i) a[j]=0;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(NAME".INP","r")){
        freopen(NAME".INP","r",stdin);
        freopen(NAME".OUT","w",stdout);
    }
    snt(N);
    cin>>l>>r;
    for(int i=l+1;i<=r;i++) if(a[2*i-1]) kq++;
    cout<<kq;
    return 0;
}
