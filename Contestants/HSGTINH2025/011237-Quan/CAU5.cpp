#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define str string
using namespace std;
ll n, k;
ll a[1000009], premin[1000009], sufmin[1000009];
void sub1(){
    ll ans=0;
    for(ll i=1; i<n; i++){
        ans=max(ans, premin[i] + sufmin[i+1]);
    }
    cout<<ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if(fopen("CAU5.INP", "r")){
		freopen("CAU5.INP", "r", stdin);
		freopen("CAU5.OUT", "w", stdout);
	}
    cin>>n>>k;
    premin[0]=sufmin[n+1]=1e11;
    for(ll i=1; i<=n; i++){
        cin>>a[i];
        premin[i]=min(premin[i-1], a[i]);
    }
    for(ll i=n; i>=1; i--){
        sufmin[i]=min(sufmin[i+1], a[i]);
    }
    if(k==2)
        sub1();
}



