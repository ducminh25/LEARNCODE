#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define str string
using namespace std;
const ll nmax=2e6;
ll n, k, a[nmax+99], gt[nmax+99], maxl=-1, d=0, gtln[nmax+9], sum[nmax+9];
void sub1(){
    ll hmax=maxl;
    ll ans=0;
    for(ll i=1; i<=n; i++){
        ans+=(hmax - a[i]);
    }
    cout<<ans;
}
void sub2(){
    ll hmax=a[1], ans=0;
    for(ll i=1; i<=n; i++){
        if(hmax >= a[i])
            ans+=(hmax - a[i]);
        else{
            hmax=maxl;
            ans+=(hmax - a[i]);
        }
    }
    cout<<ans;
}
void sub3(){
    ll ans=LLONG_MAX;
    for(ll f=1; f<=d; f++){
        ll hmax=gt[f], s=0;
        if(hmax==maxl){
            s=hmax*n - sum[n];
        }
        else{
            ll tk=upper_bound(gtln+1, gtln+n+1, hmax)-gtln-1;
            s=(tk*hmax - sum[tk]) + ((n-tk)*maxl - (sum[n] - sum[tk]));
        }
        ans=min(ans, s);
    }
    cout<<ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if(fopen("CAU2.INP", "r")){
		freopen("CAU2.INP", "r", stdin);
		freopen("CAU2.OUT", "w", stdout);
	}
    cin>>n>>k;
    for(ll i=1; i<=n; i++){
        cin>>a[i];
        maxl=max(maxl, a[i]);
        if(a[i] >= a[1])
            gt[++d]=a[i];
        if(i>1)
            gtln[i]=max(gtln[i-1], a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    gtln[1]=a[1];
    if(k==0)
        sub1();
    else if(k==-1)
        sub2();
    else
        sub3();
}


