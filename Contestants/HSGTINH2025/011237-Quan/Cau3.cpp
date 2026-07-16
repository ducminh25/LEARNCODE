#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define str string
using namespace std;
const ll nmax=2e6+99;
ll n, m, p[nmax+10], ans=0, a[nmax+10], b[nmax+10], snt[nmax+10], d[nmax+10], co[nmax+99];
bool cksub=true;
void sang(){
    for(ll i=0; i<=nmax; i++)
        p[i]=1;
    p[0]=p[1]=0;
    for(ll i=2; i*i<=nmax; i++){
        if(p[i]==1)
            for(ll j=i*i; j<=nmax; j+=i)
                p[j]=0;
    }
}
void nt(){
    snt[0]=snt[1]=1;
    for(ll i=2; i*i<=nmax; i++){
        for(ll j=i; j<=nmax; j+=i)
            if(snt[j]==0) snt[j]=i;
    }
    for(ll i=1; i<=nmax; i++){
        if(snt[i]==0)
            snt[i]=i;
    }
}
void sub1(){
    ll dem=0;
    for(ll i=1; i<=n; i++){
        bool nt=true;
        for(ll j=1; j<=m; j++){
            if(__gcd(a[i], b[j]) != 1){
                nt=false;
                break;
            }
        }
        if(nt) dem++;
    }
    cout<<dem;
}
void sub2(){
    ll ans=0;
    sort(b+1, b+m+1);
    for(ll i=1; i<=n; i++){
        ll dem=upper_bound(b+1, b+m+1, a[i]) - lower_bound(b+1, b+m+1, a[i]);
        if(dem == 0){
            ans++;
        }
    }
    cout<<ans;
}
void sub3(){
    for(ll i=1; i<=m; i++){
        ll x=b[i];
        while(x>1){
            d[snt[x]]=1;
            x/=snt[x];
        }
    }
    ll dem=0;
    for(ll i=1; i<=n; i++){
        ll x=a[i];
        bool ktra=true;
        while(x>1){
            if(d[x]==1){
                ktra=false;
                break;
            }
            x/=snt[x];
        }
        if(ktra) dem++;
    }
    cout<<dem;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if(fopen("CAU3.INP", "r")){
		freopen("CAU3.INP", "r", stdin);
		freopen("CAU3.OUT", "w", stdout);
	}
    sang(); nt();
    cin>>n>>m;
    for(ll i=1; i<=n; i++){
        cin>>a[i];
        if(p[a[i]] == 0)
            cksub=false;
    }
    for(ll i=1; i<=m; i++){
        cin>>b[i];
        if(p[b[i]] == 0)
            cksub=false;
    }
    if(cksub) sub2();
    else if(n<=1000 && m<=1000) sub1();
    else
        sub3();
}


