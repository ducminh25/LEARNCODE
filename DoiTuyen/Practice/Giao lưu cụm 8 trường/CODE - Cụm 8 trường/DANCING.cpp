#include <bits/stdc++.h>
using namespace std;
int n;
long long t=0;
int p;
int a[10000000];
int b[10000000];
int xl(int k){
    int m=0;
    int ma=0;
    int l=1;int r=n;
    while(l<=r){
        m=(l+r)/2;
        if(b[m]<k&&b[m]!=0){l=m+1;ma=m;}
        else{r=m-1;}
    }
    return ma;
}
int main()
{
    freopen("dancing.inp","r",stdin);
    freopen("dancing.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++){
        p=xl(-a[i]);
        if((p>0) && ((b[p]*a[i])<0)){
            t++;
            b[p]=0;
        }
    }
    cout<<t;
    return 0;
}
