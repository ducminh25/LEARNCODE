#include<bits/stdc++.h>
using namespace std;
#define NAME "CAU5"
#define N 5000000
int a[N+5],b[N+5],c[N+5];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(NAME".INP","r")){
        freopen(NAME".INP","r",stdin);
        freopen(NAME".OUT","w",stdout);
    }
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(k==1){
        int nn=INT_MAX;
        for(int i=1;i<=n;i++){
            nn=min(nn,a[i]);
        }
        cout<<nn;
        return 0;
    }
    if(k==2){
        int nn=INT_MAX,kq=INT_MIN;
        for(int i=1;i<=n;i++){
            nn=min(nn,a[i]);
            b[i]=nn;
        }
        nn=INT_MAX;
        for(int i=n;i>=1;i--){
            nn=min(nn,a[i]);
            c[i]=nn;
        }
        for(int i=2;i<=n;i++){
            kq=max(kq,b[i-1]+c[i]);
        }
        cout<<kq;
        return 0;
    }
    cout<<INT_MAX;
    return 0;
}
