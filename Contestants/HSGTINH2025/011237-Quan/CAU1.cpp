#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define str string
using namespace std;
const ll nmax=2e6+99;
ll l, r, p[nmax+10], ans=0;
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
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if(fopen("CAU1.INP", "r")){
		freopen("CAU1.INP", "r", stdin);
		freopen("CAU1.OUT", "w", stdout);
	}
    sang();
    cin>>l>>r;
    for(ll i=l; i<r; i++){
        if(p[i + i + 1] == 1)
            ans++;
    }
    cout<<ans;
}

