#include <bits/stdc++.h>
#define name "cau3"
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
int n , m , a[N] , b[N] , nt[N]; 
int gcd(int a , int b){
	while(b){
		int t = a % b ; 
		a = b ; 
		b = t ; 
	}
	return a ; 
}
void snt(){
	fill(nt , nt+N+1 , 1) ; 
	nt[0] = nt[1] = 0 ; 
	for(int i=2 ; i * i <= N ; ++i){
		if(nt[i]) for(int j=i*i ; j<=N; j+=i) nt[j] = 0 ; 
	}
}
set<int>  v2 ;
vi v1 ;  
void pt(int a , set<int> &v){
	for(int i=2 ; i * i <= a ; ++i){
		if(a % i == 0 ){
			v.insert(i) ; 
			while(a % i == 0 ) a/=i ;  
		}
	}
}
int cnt = 0 ; 
int cnta = 0  , cntb = 0 ;
void sub1(){
	cin>>n>>m ; 
		snt() ; 
	for(int i=0 ; i<n ; ++i){
		cin>>a[i] ; 
		if(nt[a[i]]) ++cnta ; 
	} 
	for(int i=0 ; i<m ; ++i) {
		cin>>b[i] ; 
		if(nt[b[i]]) ++cntb ; 
	}
	sort(a , a+n) ; 
	sort(b , b+m) ; 
	if(cnta == n && cntb == m ){
		
		for(int i=0 ; i<n ; ++i) {
			int j = upper_bound(b , b+m , a[i]) - a - 1 ; 
			if(b[j] == a[i]) continue ; 
			++cnt ; 
		}
		cout<<cnt ; 
	}
	else if(n <= 1e3 && m <= 1e3){
		for(int i=0 ; i<n ; ++i){
			int ok = 1 ; 
			for(int j=0 ; j<m ; ++j) {
				if(gcd(a[i] , b[j]) != 1) {
					ok = 0 ; 
					break ; 
				}
			}
			if(ok) ++cnt ; 
		}
		cout<<cnt ; 
	}
	else{
		int t = b[0] ;
		ll s;
		for(int i=0 ; i<m ; ++i) if(!nt[b[i]]) {
			s = b[i] ; 
			break ; 
		}
	
 		for(int i=1 ; i<m ; ++i){
 			if(!nt[b[i]]) {
 			t = gcd(s , b[i]) ; 
			s = s / t * b[i] ;  	
		 	}
		}
		pt(s , v2) ;
		for(int i=0 ; i<m ; ++i) if(nt[b[i]]) v2.insert(b[i]) ; 
		for(auto x : v2) v1.push_back(x) ; 
		for(int i=0 ; i<n ; ++i){
			int ok = 1 ; 
			if(a[i] == 1 ) {
				++cnt ; 
				continue ; 
			}
			if(nt[a[i]]){
				int j = upper_bound(v1.begin() , v1.end() , a[i]) - v1.begin() - 1 ;
				if(v1[j] != a[i]) ++cnt ;  
			}
			else {
				int j = upper_bound(v1.begin() , v1.end() , a[i]) - v1.begin() - 1 ;
				for(int k = 0 ; k <=j ; ++k) {
					if(a[i] % v1[k] == 0 ) {
					ok = 0 ; 
					break ; 
					}
				}
			if(ok) ++cnt ; 
			}
		
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
