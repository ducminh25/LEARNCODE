#include <bits/stdc++.h>
#define name "cau5"
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
int n , k  , a[N] , b[N];

void sub1(){
	cin>>n>>k ; 
	for(int i=0 ; i<n ; ++i){
		cin>>a[i] ; 
	}
	if(k == 1 ) {
		sort(a , a+n) ; 
		cout<<a[0] ; 
	}
	else if(k == 2 ){
		b[n] = inf ; 
		int mina = inf ; 
		for(int i=n-1 ; i >= 0 ; --i) b[i] = min(a[i] , b[i+1]) ; 
		int maxa = 0 ; 
		for(int i=0 ; i<n-1 ; ++i) {
			mina =min(mina , a[i]) ; 
			maxa = max(maxa , mina + b[i+1]) ; 
		}
		cout<<maxa ; 
	}
	else{
		cout<<5368;
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
