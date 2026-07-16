#include <bits/stdc++.h>
#define name "cau1"
#define fi first
#define se second
#define xu "\n"
#define ll int64_t
#define db double
#define vi vector<int>
#define pii pair<int,int>
#define vii vector<ll> 
using namespace std;
const int N = 1e6+6;
const int inf = 1e9;
const int mod = 1e9 + 7 ; 
int n , l , r , nt[N+1] ;
void snt(){
	fill(nt , nt+N+1 , 1) ; 
	nt[0] = nt[1] = 0 ; 
	for(int i=2 ; i*i <= N ; ++i){
		if(nt[i]) for(int j=i*i  ; j<=N ; j+=i) nt[j] = 0 ; 
	}
}
bool kt(ll a){
	if(a < 2)  return false ; 
	for(ll i = 2 ; i * i <= a ; ++i) if(a % i == 0 ) return false  ; 
	return true; 
}
ll cnt = 0  ; 
void sub1(){
	cin>>l>>r ; 
	snt() ; 
	if(r <= 500){
		for(int i=l ; i<r ; ++i){
			for(int j = l + 1 ; j<=r ; ++j){
				ll c = j * j - i * i   ; 
				if(kt(c)) {
					++cnt; 
				}
			}
		}
		cout<<cnt ; 
	}
	else{
		
		for(int i=l ; i < r ; ++i){
			ll j = i + 1 ; 
			ll c = j * j - i * i ; 
			if(kt(c)) ++cnt ; 
		}
		cout<<cnt ; 
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	freopen(name".inp" , "r" , stdin);
	freopen(name".out" , "w" , stdout);
	int e=1;
	while(e--){
		sub1();
	}
	return 0;
}
