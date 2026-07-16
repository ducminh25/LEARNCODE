#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
#define name "cau4"
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
int n , k; 
string s; 
int maxa = -1 ;
void sub1(){
	cin>>n>>k>>s ; 
	for(int len = n - 1 ; len > 1 ; --len){
		unordered_map<string , int> mp ; 
		string t = "" ; 
		for(int i=0 ; i<n ; ++i) {
			t += s[i] ; 
			if(t.size() == len ) {
				mp[t]++; 
				if(mp[t] >= k) {
					cout<<len ; 
					return ; 
				}
				t.erase(0 , 1) ; 
			}
		}
	}
	map<char , int> mp ; 
	for(int i=0 ; i<n ;++i)  {
		mp[s[i]]++;
		if(mp[s[i]] >= k ) {
			cout<<1;
			return ; 
		}
	}
	cout<<-1 ; 
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
