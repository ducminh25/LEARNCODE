#include <bits/stdc++.h>
#define int long long
const int N = 1e6;
using namespace std;
int a[N+6],n,k;
bool check(int x){
    for (int i=1;i<=n;i++){
        if (x-a[i]<0) return false;
    }
    return true;
}
void sub1(){
    int l=0,r=1e9+1,ans=-1;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    int res=0;
    for (int i=1;i<=n;i++){
        res+=ans-a[i];
    }
    cout<<res;
}
bool check1(int st,int x){
    for (int i=st;i<=n;i++){
        if (x-a[i]<0) return false;
    }
    return true;
}
void sub2(){
    int tong=0;
    int i=1;
    int h=a[1];
    while (h-a[i]>=0) tong+=h-a[i],i++;

    int l=0,r=1e9,ans=-1;
    while (l<=r){
        int mid=(l+r)/2;
        if (check1(i,mid)){
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    for (int j=i;j<=n;j++){
        tong+=ans-a[j];
    }
    cout<<tong;
}
int st[4*N];
void build(int id,int l,int r){
    if (l==r){
        st[id]=a[l];
        return ;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v){
    if (r<u||v<l) return -1e18;
    if (u<=l && r<=v) return st[id];
    int mid=(l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
int pre[N+6];
void sub3(){
    for (int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    auto cal=[&](int l,int r,int so){
        return so*(r-l+1)-(pre[r]-pre[l-1]);
    };
    int tong=1e18;
    build(1,1,n);
    for (int i=1;i<=n;i++){
        int x=get(1,1,n,1,i);
        int y=get(1,1,n,i+1,n);
        tong=min(tong,cal(1,i,x)+cal(i+1,n,y));
    }
    cout<<tong;
}
int32_t main(){
    // Calm down and stay cool
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    freopen("cau2.inp","r",stdin);
    freopen("cau2.out","w",stdout);


    cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    if (k==0){
        sub1();
    }
    else if (k==-1){
        sub2();
    }
    else sub3();
    return 0;
}
