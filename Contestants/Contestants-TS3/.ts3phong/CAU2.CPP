#include<bits/stdc++.h>
using namespace std;
#define NAME "CAU2"
#define ll long long
#define N 1000100
ll n,k,x,kq=0;
vector<ll> vt;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    if(fopen(NAME".INP","r")){
        freopen(NAME".INP","r",stdin);
        freopen(NAME".OUT","w",stdout);
    }
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>x;
        vt.push_back(x);
    }
    if(k==0){
        ll ln=vt[0];
        for(int i=1;i<n;i++) ln=max(ln,vt[i]);
        for(int i=0;i<n;i++) kq+=ln-vt[i];
        cout<<kq;
        return 0;
    }
    if(k==-1){
        ll bd=vt[0],ln=vt[0];
        for(int i=1;i<n;i++) ln=max(ln,vt[i]);
        for(int i=0;i<n;i++){
            if(vt[i]<=bd) kq+=bd-vt[i];
            else{
                bd=ln;
                kq+=bd-vt[i];
            }
        }
        cout<<kq;
        return 0;
    }
    if(k==1){
        ll ln=vt[0],z;
        for(int i=1;i<n;i++) ln=max(ln,vt[i]);
        for(int i=0;i<n;i++){
            if(vt[i]==ln){
                z=i;
                break;
            }
        }
        for(int i=z;i<n;i++) kq+=ln-vt[i];
        ll kq0=0;
        for(int i=0;i<z;i++) kq0+=ln-vt[i];
        for(int i=z-1;i>=0;i--){
            ll lnn=vt[i];
            ll q=-1;
            for(int j=0;j<z;j++){
                if(vt[j]>lnn){
                    q=j;
                    break;
                }
            }
            ll kq1=0,kq2=0;
            bool kt2=1;
            for(int j=0;j<z;j++){
                if(vt[j]<=lnn) kq1+=lnn-vt[j];
                else{
                    kt2=0;
                    break;
                }
            }
            if(kt2) kq0=min(kq0,kq1);
            if(q!=-1){
                for(int j=0;j<z;j++){
                    if(vt[j]<=lnn) kq2+=lnn-vt[j];
                    else{
                        lnn=ln;
                        kq2+=lnn-vt[j];
                    }
                }
                kq0=min(kq0,kq2);
            }
        }
        cout<<kq0+kq;
        return 0;
    }
    return 0;
}
