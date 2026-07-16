#include <bits/stdc++.h>
#define name "cau2"
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
int n , a[N] , k , maxa = 0 , mina = inf ;
ll d[N] ; 
ll dist(int m , int maxa ){
	ll sum = 0 ; 
	int b = m ; 
	for(int i=0 ; i<n ; ++i) {
		if(a[i] > b)  b = maxa ; 
		sum += b - a[i]  ; 
	}
	return sum ; 
}
void sub1(){
	cin>>n>>k ; 
	for(int i=0 ; i<n ; ++i){
		cin>>a[i] ; 
		maxa = max(maxa , a[i]) ; 
		mina= min(mina , a[i]) ; 
	}
	if(k == 0 ) {
		ll sum = 0 ; 
		for(int i=0 ; i<n ; ++i) sum += maxa - a[i] ; 
		cout<<sum ; 
	}
	else if(k == -1){
		ll sum = 0 ; 
		int maxb = a[0] ; 
		for(int i=1 ; i<n ;++i){
			if(a[i] > maxb ) maxb = maxa ; 
			sum += maxb - a[i]  ; 
		}
		cout<<sum ; 
	}
	else{
		ll minl = 1e18 , sum = 0 ; 
		int b = a[0] , c; 
		d[n] = 0 ; 
		for(int i=n-1 ; i>=0 ; --i) d[i] = d[i+1] + maxa - a[i] ; 
		int j = 0 ; 
		for(int i=0 ; i<n ; ++i){
			if(a[i] > b ) {
				minl = min(minl , sum + d[i]) ; 
				sum += (i - 1) *(a[i] - b) + a[i] - b ;  
				b = a[i] ;  
			}
			sum += b - a[i] ; 
		}
		cout<<minl ; 
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
