#include<bits/stdc++.h>
using namespace std;
#define NAME "CAU3"
#define N 1000100
int n,m,kq=0,a[N+5],b[N+5];
bool nt[N+5],d[N+5]={0};
void snt(int n){
    fill(nt+1,nt+n+1,1);
    nt[0]=nt[1]=0;
    for(int i=2;i*i<=n;i++){
        if(nt[i]){
            for(int j=i*i;j<=n;j+=i) nt[j]=0;
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
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=m;i++){
        d[b[i]]=1;
        while(b[i]%2==0){
            d[2]=1;
            b[i]/=2;
        }
        for(int j=3;j*j<=b[i];j+=2){
            while(b[i]%j==0){
                d[j]=1;
                b[i]/=j;
            }
        }
        if(b[i]!=1) d[b[i]]=1;
    }
    for(int i=1;i<=n;i++){
        bool kt=1;
        if(d[a[i]]) kt=0;
        if(a[i]==1) kq++,kt=0;
        if(kt){
            for(int j=2;j*j<=a[i];j++){
                if(a[i]%j==0){
                    if(d[j]){
                        kt=0;
                        break;
                    }
                }
                while(a[i]%j==0) a[i]/=j;
            }
        }
        if(kt&&a[i]!=1){
            if(d[a[i]]) kt=0;
        }
        if(kt) kq++;
    }
    cout<<kq;
    return 0;
}
