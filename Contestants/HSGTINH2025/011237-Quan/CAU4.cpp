#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define str string
using namespace std;
ll n, k;
str s;
map<string, ll> mp;
void sub1(){
    ll ans=-1;
    for(ll i=1; i<=n; i++){
        for(ll j=i; j<=n; j++){
            string t=s.substr(i, j-i+1);
            ll dem=0;
            string s1="";
            for(ll z=1; z<=n; z++){
                s1=s1 + s[z];
                if(s1.size() > j-i+1)
                    s1.erase(0, 1);
                if(s1==t)
                    dem++;
                //if(i==1 && j==2) cout<<s1<<' '<<t<<'\n';
                if(dem>=k){
                    ans=max(ans, j-i+1);
                    break;
                }
            }
        }
    }
    cout<<ans;
}
void sub2(){
    ll ans=-1;
    for(ll len=1; len<=n; len++){
        for(ll i=1; i+len-1<=n; i++){
            string t=s.substr(i, len);
            mp[t]++;
            if(mp[t] >= k){
                ans=max(ans, len);
                break;
            }
        }
        mp.clear();
    }
    cout<<ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	if(fopen("CAU4.INP", "r")){
		freopen("CAU4.INP", "r", stdin);
		freopen("CAU4.OUT", "w", stdout);
	}
    cin>>n>>k;
    cin>>s;
    s=' '+s;
    if(n<=100)
        sub1();
    else sub2();
}


